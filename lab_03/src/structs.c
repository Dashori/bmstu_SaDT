#include "structs.h"

int *allocate_arr(int n_zero)
{
    int *arr;

    arr = calloc(n_zero, sizeof(int));

    if (arr == NULL)
        return NULL;
    
    return arr;
}

int **allocate_matrix(int n, int m)
{
    int **matrix;
    matrix = calloc(n , sizeof(int*));
    if (!matrix)
        return NULL;

    int *str;
    str = calloc(n * m , sizeof(int));

    if (!str)
        return NULL;
    
    for(int i = 0; i < n; i++)
        matrix[i] = str + i * m;

    return matrix;
}

void free_matrix(int **mtr)
{
    free(mtr[0]);
    free(mtr);
}

void free_arr(int *arr)
{
    free(arr);
}

void print_matrix(struct matrix_full mtr)
{
    for (int i = 0; i < mtr.n; i++)
    {
        for (int j = 0; j < mtr.m; j++)
            printf("%d ", mtr.mtr[i][j]);
        printf("\n");
    }
}

void print_arr(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void print_str(struct str_matrix str_mtr)
{
    for(int i = 0; i < str_mtr.n; i++)
        printf("%d ", str_mtr.mtr[i]);
    printf("\n");
}
