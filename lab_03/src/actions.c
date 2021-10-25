#include "actions.h"

void multiplicate_matrix(struct str_matrix str, struct matrix_full mtr, struct str_matrix *res)
{
    for (int k = 0; k < mtr.m; k++)
    {
        int el = 0;
        for (int j = 0; j < str.n; j++)
            el += str.mtr[j] * mtr.mtr[j][k];
        res->mtr[k] = el;
    }
}

void multiplicate_sparse(struct sparse_matrix str, struct sparse_matrix mtr, struct sparse_matrix *res_sparse, struct str_matrix *res)
{

    printf("%d ", mtr.str);
    printf(" HEREE\n");

    if (!str.n_zero)
        return;

    int k = 0;
    for(int i = 0; i < mtr.col; i++)
    {
        for(int j = mtr.JA[i]; j < mtr.JA[i + 1]; j++)
            if(str.JA[mtr.IA[j] + 1] - str.JA[mtr.IA[j]] != 0)    
                res->mtr[k] += str.A[str.JA[mtr.IA[j]]] * mtr.A[j];
        k++;
    }

    printf(" res: \n");
    for(int i = 0; i < res->n; i++)
        printf("%d ", res->mtr[i]);

    res->n = 0;
    res_sparse->str = 0;
}

