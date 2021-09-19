#!/bin/bash

echo
echo NEGATIVE TESTS
echo 

for file in ./neg_??_in.txt
do
    ./neg_test.sh "$file"
done

echo 
echo POSITIVE TEST
echo 

for file in pos_??_in.txt
do
    ./pos_test.sh "$file"
done

echo