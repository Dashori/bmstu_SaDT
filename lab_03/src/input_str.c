#include "input_str.h"

int create_sparse_string(struct str_matrix *str, struct sparse_matrix *str_spr)
{
    printf("ok");
    if ((str_spr->A = allocate_arr(str->n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((str_spr->IA = allocate_arr(str->n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((str_spr->JA = allocate_arr(str->n + 1)) == NULL)
        return ERROR_MEMORY;

    return EXIT_SUCCESS;
}


int read_param_str(struct str_matrix *str_mtr)
{
    printf("Введите количество элементов в матрице-строке: ");
    if(scanf("%d", &str_mtr->n) != 1 || str_mtr->n < 1)
    {
        printf("Неверно введен размер матрицы-строки.\n");
        return ERROR_PARAM;
    }    

    printf("Введите количество ненулевых элементов в матрице-строк: ");
    if(scanf("%d", &str_mtr->n_zero) != 1 || str_mtr->n_zero < 1
    || str_mtr->n_zero > str_mtr->n)
    {
        printf("Неверно введено количество ненулевых элементов матрицы-строки.\n");
        return ERROR_PARAM;
    }

    return EXIT_SUCCESS;
}

int read_element_str(struct str_matrix *str_mtr)
{
    int col, el;
    int n_zero_2 = str_mtr->n_zero;

    printf("\nНумерация столбцов матрицы-строки начинается с 0!\n");

    for(int i = 0; i < str_mtr->n_zero; i++)
    {
        printf("\nВведите индекс для нового элемента: ");
        if(scanf("%d", &col) != 1 || col < 0 || col > str_mtr->n)
        {
            printf("Неверно введен индекс для нового элемента.\n");
            return ERROR_PARAM;
        }

        if (str_mtr->mtr[col] != 0)
        {
            printf("\nЭлемент на этой позиции уже введен.\n\
Количество ненулевых элементов будет уменьшено на 1.\n\n");
            n_zero_2--;
        }
        
        printf("Введите элемент для позиции %d: ", col);
        if(scanf("%d", &el) != 1 || el == 0)
        {  
            printf("Неверно введен элемент матрицы-строки.\n");
            return ERROR_ELEMENT;
        }

        str_mtr->mtr[col] = el;
    }

    printf("Введено %d ненулевых элементов из %d выбранных.\n", n_zero_2, str_mtr->n_zero);
    str_mtr->n_zero = n_zero_2;

    return EXIT_SUCCESS;
}   

int create_rand_str(struct str_matrix *str_mtr)
{
    if ((str_mtr->mtr = calloc(str_mtr->n , sizeof(int))) == NULL)
        return ERROR_MEMORY;

    for (int i = 0; i < str_mtr->n_zero; i++)
    {   
        int str = rand() % str_mtr->n;

        if (str_mtr->mtr[str] == 0)
            str_mtr->mtr[str] = 1 + rand() % 100;
        
        else
            i--;
    }

    return EXIT_SUCCESS;
}
