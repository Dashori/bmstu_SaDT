#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

#define ERROR_KEY 1

void description(void);
void menu(void);
void print_info_arr(struct arr_stack array);
void print_arr(struct arr_stack array);
void print_list(struct list_stack list);
void print_free_list(double *array[50], size_t len_array);

#endif