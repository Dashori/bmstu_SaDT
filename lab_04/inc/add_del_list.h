#ifndef ADD_DEL_LIST_H
#define ADD_DEL_LIST_H

#define ERROR_ELEMENT_LIST 5

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

int allocate_el_list(struct list_stack *list);
void pop_list_element(struct list_stack *list, double *array[MAX_SIZE], size_t *len_array);

#endif