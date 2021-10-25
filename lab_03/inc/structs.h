#ifndef STRUCTS_H
#define STRUCTS_H 

#include <stdlib.h>
#include <stdio.h>

struct sparse_matrix
{
    int str;
    int col;
    int n_zero;
    
    int *A;
    int *IA;
    int *JA;
};

struct matrix_full
{
    int **mtr;
    int n;
    int m;
    int n_zero;
};

struct str_matrix
{
    int *mtr;
    int n;
    int n_zero;
};

int *allocate_arr(int n_zero);
int **allocate_matrix(int n, int m);
void free_matrix(int **mtr);
void free_arr(int *arr);
void print_matrix(struct matrix_full mtr);
void print_arr(int *arr, int n);
void print_str(struct str_matrix str_mtr);


#endif