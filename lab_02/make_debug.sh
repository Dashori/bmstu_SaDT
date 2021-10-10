#!/bin/bash

gcc -std=c99 -Wfloat-equal -Wfloat-conversion -Wvla -g3 --coverage -c *.c
gcc --coverage *.o -o app.exe
