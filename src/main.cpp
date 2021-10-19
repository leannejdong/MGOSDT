#include "main.hpp"

int main(int argc, char *argv[]) {
	struct pollfd file_descriptors;
	file_descriptors.fd = 0; /* this is STDIN */
	file_descriptors.events = POLLIN;
	bool standard_input = poll(& file_descriptors, 1, 0) == 1;
	
	// Check program input
	if ((standard_input && (argc < 1 || argc > 2)) || (!standard_input && (argc < 2 || argc > 3))) {
		std::cout << "Usage: gosdt [path to feature set] ?[path to config]" << std::endl;
		return 0;
	}
	if (argc >= 2 && !std::ifstream(argv[1]).good()) {
		std::cout << "File Not Found: " << argv[1] << std::endl;
		return 1;
	}
	if (argc >= 3 && !std::ifstream(argv[2]).good()) {
		std::cout << "File Not Found: " << argv[2] << std::endl;
		return 1;
	}
	
	if ((standard_input && argc == 2) || (!standard_input && argc == 3)) {
		// Use custom configuration if provided
		std::ifstream configuration(argv[argc - 1]);  // argc = 3, so argv[2], so configuration(config.json)
		Configuration::configure(configuration);
	}

	// Print messages to help user ensure they've provided the correct inputs
	if (Configuration::verbose) {
		std::cout << "Generalized Optimal Sparse Decision Tree" << std::endl;
		std::cout << "Using data set: " << argv[1] << std::endl;
	}
	std::string result;
	mgosdt::GOSDT model;
	if (standard_input) {
		model.fit(std::cin, result);
	} else {
		std::ifstream data(argv[1]);
		model.fit(data, result);
	}
	if (Configuration::model == "" || Configuration::verbose) { std::cout << result << std::endl; }

    std::cout << "There are " << argc << " arguments:\n";
    for(int count{0}; count < argc; ++count){
        std::cout << count << ' ' << argv[count] << '\n';
    }
    pid_t pid = getpid();
    std::cout << "pid_mgosdt: " << pid << "\n";
	return 0;
}

/*!
 * the program is trying to check to see if any data is available on stdin,
 * and if it is, it calls model.fit() with cin,
 * otherwise it opens a file based on the path given on the command line
 * and calls model.fit() with that instead
 */
