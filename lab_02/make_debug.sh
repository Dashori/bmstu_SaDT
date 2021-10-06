#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -g3 --coverage -c read_file.c add_del_flat.c menu.c main.c 
gcc --coverage menu.o read_file.o add_del_flat.o main.o -o app.exe
