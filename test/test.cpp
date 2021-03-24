#include "test.hpp"
#include "test_bitmask.hpp"
#include "test_index.hpp"
#include "test_queue.hpp"
#include "test_consistency.hpp"
/*! The try-catch block provides some logic how to run a test.
 * It runs the test inside a try block.
 * Adds the number of failures.
 * If there is an exception it prints out some details of the exception.
 * We are trying to avoid duplicating the logic
 * So instead of doing the same logic 3 times for the 3 different test functions, it uses a loop.
 * We create the map to iterate over
 * the map has what is different about each test, which is the name of the test and the actual functions that runs the test
 * the fact that it is a map does not matter, we are basically using the map as a list of pairs.
 */
int main() {
    int failures = 0;
    std::map< std::string, int (*)(void) > units;
    units["Bitmask"] = test_bitmask;
    units["Index"] = test_index;
    units["Queue"] = test_queue;
    units["Consistency"] = test_consistency;

    for (auto iterator = units.begin(); iterator != units.end(); ++iterator ) {
        try {
            failures += run_tests((*iterator).first, (*iterator).second);
        } catch (char const * exception) {
            std::cout << "\033[1;31m" << "Uncaught Exception in "  << (*iterator).first << " Tests" << "\033[0m" << "\n";
            std::cout << "\033[1;31m" << "Uncaught Exception: "  << exception << "\033[0m" << "\n";
            failures += 1;
        }
    }

    if (failures == 0) {
        std::cout << "\033[1;32m" << "All Tests Passed" << "\033[0m" << "\n";
        return 0;
    } else {
        std::cout << "\033[1;31m" << failures << " Tests Failed" << "\033[0m" << "\n";
        return 1;
    }
}