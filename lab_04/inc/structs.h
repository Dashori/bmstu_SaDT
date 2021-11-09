#ifndef STRUCTS_H
#define STRUCTS_H

#define ERROR_SIZE 2
#define ERROR_MEMORY 3

#define MAX_SIZE 5000
#define MIN_SIZE 1

#include <stdlib.h>
#include <stdio.h>

struct arr_stack
{
    int size_arr; //размер массива
    int cur_size; //количество свободных элементов в массиве
    int count_left; //последний элемент в левом стеке
    int count_right; //последний элемент в правом стеке
    double *arr; //массив с правым и левом стеке
};

struct list_element
{
    double elem; //значение элемента списка
    int count; //количество элементов в списке
    struct list_element *next; //указатель на след ячейку списка
};

struct list_stack
{
    struct list_element *element;
};

int allocate_array(struct arr_stack *array);

#endif