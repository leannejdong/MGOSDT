#include "../src/model.hpp"
#include <cassert>
static void test_model(){

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
    auto inputs = nlohmann::json::parse(source);
    Model model;
    model.summarize(inputs);
    //std::cout << inputs.dump(4) << "\n";

    json expect = json::parse(R"(
               {
                        "children": [
                            {
                                "in": [
                                7,
                                        null
                                ],
                                "then": {
                                    "complexity": 0.009999999776482582,
                                            "loss": 0.0,
                                            "name": "y",
                                            "prediction": 0
                                }
                            },
                            {
                                "in": [
                                3,
                                        7
                                ],
                                "then": {
                                    "complexity": 0.009999999776482582,
                                            "loss": 0.0,
                                            "name": "y",
                                            "prediction": 1
                                }
                            },
                            {
                                "in": [
                                        null,
                                        3
                                ],
                                "then": {
                                    "complexity": 0.009999999776482582,
                                    "loss": 0.0,
                                    "name": "y",
                                    "prediction": 0
                                }
                            }
                        ],
                        "feature": 0,
                        "name": "x",
                        "type": "integral"
                }
    )");
    assert(inputs == expect);
    std::cout << inputs.dump(4) << "\n";

}