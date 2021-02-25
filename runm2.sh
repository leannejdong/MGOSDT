#!/bin/bash
#gosdt m2.csv config.json 2>&1 | tee outputs/m2.json
gosdt m2.csv config.json >outputs/m2.json
gosdt syn1.txt ./experiments/configurations/debug.json >outputs/syn1.json
