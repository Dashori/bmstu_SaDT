#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STR 200
#define MAX_COL 200

#define ERROR_KEY 1
#define ERROR_READ 2
#define ERROR_PARAM 3
#define ERROR_MEMORY 4
#define ERROR_ELEMENT 5

#define EPSI 1e-6

int read_param(int *n, int *m);
int input_non_zero(int *n_zero, int n, int m);
int read_matrix(int ***MTR, int n, int m, int n_zero);
void print_matrix(int **MTR, int n, int m);
// void create_A(int **MTR, int *A, int *IA, int n, int m, int n_zero);
void create_sparse(int **MTR, int **A, int **IA, int **JA, int n, int m, int n_zero);
// void create_IA(int **MTR, int *IA, int *JA, int n, int m, int n_zero);
// void create_JA(int **MTR, int *JA, int *A, int *IA, int n_zero);
void free_matrix(int **MTR);

#endif