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
