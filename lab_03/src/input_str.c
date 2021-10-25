#include "input_str.h"

void create_arrays_str(struct str_matrix str, struct sparse_matrix *str_spr)
{
    str_spr->JA[0] = 0;
    int cur = 0;
    
    for(int j = 0; j < str.n; j++)
    {
        int count_JA = 0;
        if(str.mtr[j] != 0)
        {
            str_spr->A[cur] = str.mtr[j];
            str_spr->IA[cur] = 0;
            cur++;
            count_JA++;
        } 
        str_spr->JA[j + 1] = count_JA + str_spr->JA[j];
    }
}

int create_sparse_string(struct str_matrix str, struct sparse_matrix *str_spr)
{
    if ((str_spr->A = allocate_arr(str.n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((str_spr->IA = allocate_arr(str.n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((str_spr->JA = allocate_arr(str.n + 1)) == NULL)
        return ERROR_MEMORY;

    str_spr->str = 1;
    str_spr->col = str.n;
    str_spr->n_zero = str.n_zero;
        
    create_arrays_str(str, str_spr);

    return EXIT_SUCCESS;
}


int read_param_str(struct str_matrix *str_mtr)
{
    printf("Введите количество элементов в матрице-строке(от 1 до 5000): ");
    if(scanf("%d", &str_mtr->n) != 1 || str_mtr->n < 1 || str_mtr->n > 5000) 
    {
        printf("Неверно введен размер матрицы-строки.\n");
        return ERROR_PARAM;
    }    

    printf("Введите количество ненулевых элементов в матрице-строк: ");
    if(scanf("%d", &str_mtr->n_zero) != 1 || str_mtr->n_zero < 0
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
        if(scanf("%d", &col) != 1 || col < 0 || col >= str_mtr->n)
        {
            printf("Неверно введен индекс для нового элемента.\n");
            return ERROR_PARAM;
        }

        if (str_mtr->mtr[col] != 0)
        {
            printf("\nЭлемент на этой позиции уже введен.\n\
Количество ожидаемых ненулевых элементов будет уменьшено на 1.\n");
            n_zero_2--;
        }
        
        printf("Введите элемент для позиции %d: ", col);
        if(scanf("%d", &el) != 1)
        {  
            printf("Неверно введен элемент матрицы-строки.\n");
            return ERROR_ELEMENT;
        }

        if(el == 0)
        {
            printf("\nВы ввели 0.\n\
Количество ожидаемых ненулевых элементов будет уменьшено на 1.\n");
            n_zero_2--;
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
