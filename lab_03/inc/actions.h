#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "structs.h"

void multiplicate_matrix(struct str_matrix str, struct matrix_full mtr, struct str_matrix *res, clock_t *res_time);
void multiplicate_sparse(struct sparse_matrix str, struct sparse_matrix mtr, struct sparse_matrix *res_sparse, clock_t *res_time);
#endif