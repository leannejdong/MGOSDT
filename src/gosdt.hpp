#ifndef GOSDT_H
#define GOSDT_H

#define SIMDPP_ARCH_X86_SSE4_1

#include <iostream>

#include <thread>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <chrono>
#include <future>
#include <boost/dynamic_bitset.hpp>
#include <vector>
#include <string>

#include <alloca.h>

#include <nlohmann/json.hpp>

#include "integrity_violation.hpp"
#include "optimizer.hpp"
namespace mgosdt{

using json = nlohmann::json;
    /// The main interface of the library
    /// Note that the algorithm behaviour is modified using the static configuration object using the Configuration class
    class GOSDT {
    public:
        /// @param config_source: string stream containing a JSON object of configuration parameters
        /// @note: See the Configuration class for details about each parameter
        static void configure(std::istream & config_source);

        /// @require: The CSV must contain a header.
        /// @require: Scientific notation is currently unsupported by the parser, use long form decimal notation
        /// @require: All rows must have the same number of entries
        /// @require: all entries are comma-separated
        /// @require: Wrapping quotations are not stripped
        /// @param data_source: string containing a CSV of training_data
        /// @modifies result: Contains a JSON array of all optimal models extracted
        void fit(std::istream & data_source, std::string & result);

        /// @require: The CSV must contain a header.
        /// @require: Scientific notation is currently not supported by the parser, use long form decimal notation
        /// @require: All rows must have the same number of entries
        /// @require: all entries are comma-separated
        /// @require: Wrapping quotations are not stripped
        /// @param data_source: string containing a CSV of training_data
        /// @modifies models: Set of models extracted from the optimization
        void fit(std::istream & data_source, std::unordered_set< Model > & models);
    private:
        float time = 0.0;
        unsigned int size = 0;
        unsigned int iterations = 0;
        unsigned int status = 1;

        /// @param id: The worker ID of the current thread
        /// @param optimizer: optimizer object which will assign work to the thread
        /// @modifies return_reference: reference for returning values to the main thread
        //static void work(int const id, Optimizer & optimizer, int & return_reference);
        static int work(int const id, Optimizer & optimizer);
    };
}


#endif
