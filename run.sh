#!/bin/bash
#gosdt m2.csv config.json 2>&1 | tee outputs/m2.json

./gosdt experiments/datasets/monk_1/m1.csv experiments/configurations/debug.json >outputs/m1.json
./gosdt m2.csv experiments/configurations/debug.json >outputs/m2.json
./gosdt experiments/datasets/monk_3/m3.csv experiments/configurations/debug.json >outputs/m3.json
./gosdt syn3.txt experiments/configurations/debug.json >outputs/syn3.json
./gosdt syn5.txt experiments/configurations/debug.json >outputs/syn5.json
#./gosdt tic-tac-toe.csv experiments/configurations/debug.json >outputs/tic-tac-toe.json 2>&1
