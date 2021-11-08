#include "gosdt.hpp"

#define _DEBUG true
#define THROTTLE false

void mgosdt::GOSDT::configure(std::istream & config_source) { Configuration::configure(config_source); }

void mgosdt::GOSDT::fit(std::istream & data_source, std::string & result) {
    std::unordered_set< Model > models;
    fit(data_source, models);
    json output = json::array();
    for (auto& model: models) {
        json object = json::object();
        model.to_json(object);
        output.push_back(object);
    }
    result = output.dump(2);
}

void mgosdt::GOSDT::fit(std::istream & data_source, std::unordered_set< Model > & models) {
    if(Configuration::verbose) { std::cout << "Using configuration: " << Configuration::to_string(2) << "\n"; }

    if(Configuration::verbose) { std::cout << "Initializing Optimization Framework" << "\n"; }
    Optimizer optimizer;
    optimizer.load(data_source);

    GOSDT::time = 0.0;
    GOSDT::size = 0;
    GOSDT::iterations = 0;
    GOSDT::status = 0;

    std::vector< std::future<int> > workers;
    std::vector< int > iterations(Configuration::worker_limit);

    if(Configuration::verbose) { std::cout << "Starting Optimization" << "\n"; }
    auto start = std::chrono::steady_clock::now();

    optimizer.initialize();
    for (unsigned int i = 0; i < Configuration::worker_limit; ++i) {
        workers.emplace_back(std::async(std::launch::async, work, i, std::ref(optimizer)));
    }

    for (auto &fut: workers) {
        fut.wait();
    }
    auto stop = std::chrono::steady_clock::now(); // Stop measuring training time
    GOSDT::time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() / 1000.0;
    if(Configuration::verbose) { std::cout << "Optimization Complete" << "\n"; }

    for(const auto &iter : iterations) {GOSDT::iterations += iter;}
    GOSDT::size = optimizer.size();

    if (Configuration::timing != "") {
        std::ofstream timing_output(Configuration::timing, std::ios_base::app);
        timing_output << GOSDT::time;
    }

    if(Configuration::verbose) {
        std::cout << "Training Duration: " << GOSDT::time << " seconds" << "\n";
        std::cout << "Number of Iterations: " << GOSDT::iterations << " iterations" << "\n";
        std::cout << "Size of Graph: " << GOSDT::size << " nodes" << "\n";
        float lowerbound, upperbound;
        optimizer.objective_boundary(& lowerbound, & upperbound);
        std::cout << "Objective Boundary: [" << lowerbound << ", " << upperbound << "]" << "\n";
        std::cout << "Optimality Gap: " << optimizer.uncertainty() << "\n";
    }

    // try 
    { // Model Extraction
        if (!optimizer.complete()) {
            if (Configuration::diagnostics) {
                std::cout << "Non-convergence Detected. Beginning Diagnosis" << "\n";
                optimizer.diagnose_non_convergence();
                std::cout << "Diagnosis complete" << "\n";
            }
        }

        optimizer.models(models);//calls the set of optimal trees via the root key which identifies the root of the dependency graph

        if (Configuration::model_limit > 0 && models.size() == 0) {
            GOSDT::status = 1;
            if (Configuration::diagnostics) {
                std::cout << "False-convergence Detected. Beginning Diagnosis" << "\n";
                optimizer.diagnose_false_convergence();
                std::cout << "Diagnosis complete" << "\n";
            }
        }

        if (Configuration::verbose) {
            std::cout << "Models Generated: " << models.size() << "\n";
            if (optimizer.uncertainty() == 0.0 && models.size() > 0) {
                std::cout << "Loss: " << models.begin() -> loss() << "\n";
                std::cout << "Complexity: " << models.begin() -> complexity() << "\n";
            } 
        }
        if (Configuration::model != "") {
            json output = json::array();
            for(Model model : models) {
                json object = json::object();
                model.to_json(object);
                output.push_back(object);
            }

            std::string result = output.dump(2);
            if(Configuration::verbose) { std::cout << "Storing Models in: " << Configuration::model << "\n"; }
            std::ofstream out(Configuration::model);
            out << result;
        }
    }
}

 int mgosdt::GOSDT::work(int const id, Optimizer & optimizer) {
    unsigned int iterations = 0;
    try {
        while (optimizer.iterate(id)) { iterations += 1; }
    } catch( IntegrityViolation exception ) {
        std::cout << exception.to_string() << "\n";
        throw std::move(exception);
    }
    return iterations;
}