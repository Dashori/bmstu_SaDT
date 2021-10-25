#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "input_mtr.h"
#include "input_str.h"
#include "actions.h"

#define ERROR_MULTI 6

void print_rules(void);
void print_menu(void);
int do_actions(int key, struct matrix_full *mtr, struct sparse_matrix *mtr_spr, 
struct str_matrix *str, struct sparse_matrix *str_spr,
struct str_matrix *res, struct sparse_matrix *res_spr, int *flag_matrix, int *flag_str);

#endif