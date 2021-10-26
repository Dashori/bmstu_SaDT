#ifndef INPUT_STR_H
#define INPUT_STR_H


#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_PARAM 3
#define ERROR_MEMORY 4
#define ERROR_ELEMENT 5

int read_param_str(struct str_matrix *str_mtr);
int read_element_str(struct str_matrix *str_mtr);
int create_sparse_string(struct str_matrix str, struct sparse_matrix *str_spr);
int create_rand_str(struct str_matrix *str_mtr);
void print_str(struct str_matrix str_mtr);

#endif