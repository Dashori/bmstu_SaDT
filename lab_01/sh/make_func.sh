#!/bin/bash

cd ./func_tests || exit 1

./all_test.sh

cd .. 

gcov *.c -r
