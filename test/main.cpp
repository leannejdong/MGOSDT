/*!
 * Created by leanne on 3/8/21.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/model.hpp"

//int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }
//
//TEST_CASE("testing the factorial function") {
//    CHECK(factorial(1) == 1);
//    CHECK(factorial(2) == 2);
//    CHECK(factorial(3) == 6);
//    CHECK(factorial(10) == 3628800);
//}

constexpr auto source =
        "    {"
        "        \"false\": {"
        "            \"complexity\": 0.009999999776482582,"
        "            \"loss\": 0.0,"
        "            \"name\": \"y\","
        "            \"prediction\": 0"
        "        },"
        "        \"feature\": 0,"
        "        \"name\": \"x\","
        "        \"reference\": 3,"
        "        \"relation\": \">=\","
        "        \"true\": {"
        "            \"false\": {"
        "                \"complexity\": 0.009999999776482582,"
        "                \"loss\": 0.0,"
        "                \"name\": \"y\","
        "                \"prediction\": 1"
        "            },"
        "            \"feature\": 0,"
        "            \"name\": \"x\","
        "            \"reference\": 7,"
        "            \"relation\": \">=\","
        "            \"true\": {"
        "                \"complexity\": 0.009999999776482582,"
        "                \"loss\": 0.0,"
        "                \"name\": \"y\","
        "                \"prediction\": 0"
        "            },"
        "            \"type\": \"integral\" "
        "        },"
        "        \"type\": \"integral\" "
        "    }";


TEST_CASE(" testing the summarize function") {
    auto inputs = nlohmann::json::parse(source);
    Model model;
    model.summarize(inputs);
    std::cout << inputs.dump(4) << "\n";
}