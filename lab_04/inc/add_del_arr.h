#ifndef ADD_DEL_ARR_H
#define ADD_DEL_ARR_H

#define ERROR_ELEMENT_ARR 4

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

int add_left(struct arr_stack *array);
int add_right(struct arr_stack *array);
void del_left(struct arr_stack *array);
void del_right(struct arr_stack *array);

#endif