#include "input_mtr.h"

int read_param(struct matrix_full *mtr)
{
    printf("Введите количество строк матрицы(от 1 до 5000): ");
    if(scanf("%d", &mtr->n) != 1)
        return ERROR_READ;

    if (mtr->n < 1 || mtr->n > MAX_STR)
        return ERROR_PARAM;

    printf("Введите количество столбцов матрицы(от 1 до 5000): ");

    if(scanf("%d", &mtr->m) != 1)
        return ERROR_READ;

    if (mtr->m < 1 || mtr->m > MAX_STR)
        return ERROR_PARAM;

    return EXIT_SUCCESS;
}

int input_non_zero(struct matrix_full *mtr)
{
    printf("Введите количество ненулевых элементов матрицы: ");
    if (scanf("%d", &mtr->n_zero) != 1)
    {
        printf("Неверное количество ненулевых элементов матрицы.\n");
        return ERROR_READ;
    }

    if (mtr->n_zero < 0 || mtr->n_zero > mtr->n * mtr->m )
    {
        printf("Неверное количество ненулевых элементов матрицы.\n");
        return ERROR_PARAM;
    }

    return EXIT_SUCCESS;
}

int read_elements(struct matrix_full *mtr)
{
    int str, col;
    int n_zero_2 = mtr->n_zero;
    int el;

    printf("\nНумерация строк и столбцов матрицы начинается с 0!\n");

    for(int i = 0; i < mtr->n_zero; i++)
    {
        printf("\nВведите строку для нового элемента (по счёту №%d): " , i + 1);
        if (scanf("%d", &str) != 1 || str < 0 || str >= mtr->n)
        {
            printf("Неверно введёно число строк матрицы.\n");
            return EXIT_FAILURE;
        }

        printf("Введите столбец для нового элемента: ");
        if (scanf("%d", &col) != 1 || col < 0 || col >= mtr->m)
        {
            printf("Неверно введёно число столбцов матрицы.\n");
            return EXIT_FAILURE;
        }
        if (mtr->mtr[str][col] != 0)
        {
            printf("\nЭлемент на этой позиции уже введен.\n\
Количество ожидаемых ненулевых элементов будет уменьшено на 1.\n\n");
            n_zero_2--;
        }

        printf("Введите элемент матрицы: ");
        if (scanf("%d", &el) != 1)
        {
            printf("Неверно введён числовой элемент матрицы.\n");
            return EXIT_FAILURE;
        }
        if (el == 0)
        {
            printf("\nВы ввели 0.\n\
Количество ожидаемых ненулевых элементов будет уменьшено на 1.\n\n");
            n_zero_2--;
        }

        mtr->mtr[str][col] = el;     
    }
 
    printf("Введено %d ненулевых элементов из %d выбранных.\n", n_zero_2, mtr->n_zero);
    mtr->n_zero = n_zero_2;

    return EXIT_SUCCESS;
}

void create_arrays(struct matrix_full mtr, struct sparse_matrix *mtr_spr)
{
    mtr_spr->JA[0] = 0;
    int cur = 0;
    
    for (int i = 0; i < mtr.m; i++)
    {
        int count_JA = 0;
        for(int j = 0; j < mtr.n; j++)
            if(mtr.mtr[j][i] != 0)
            {
                mtr_spr->A[cur] = mtr.mtr[j][i];
                mtr_spr->IA[cur] = j;
                cur++;
                count_JA++;
            } 

        mtr_spr->JA[i + 1] = count_JA + mtr_spr->JA[i];
    }
}

int create_sparse_matrix(struct matrix_full mtr, struct sparse_matrix *mtr_spr)
{
    if ((mtr_spr->A = allocate_arr(mtr.n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((mtr_spr->IA = allocate_arr(mtr.n_zero)) == NULL)
        return ERROR_MEMORY;
    if ((mtr_spr->JA = allocate_arr(mtr.m + 1)) == NULL)
        return ERROR_MEMORY;

    mtr_spr->str = mtr.n;
    mtr_spr->col = mtr.m;
    mtr_spr->n_zero = mtr.n_zero;

    create_arrays(mtr, mtr_spr);

    return EXIT_SUCCESS;
}

int read_matrix(struct matrix_full *mtr)
{  
    if((mtr->mtr = allocate_matrix(mtr->n, mtr->m)) == NULL)
        return ERROR_MEMORY;
    
    if (read_elements(mtr))
    {
        free_matrix(mtr->mtr);
        return ERROR_ELEMENT;
    }

    return EXIT_SUCCESS;
}

int create_rand_matrix(struct matrix_full *mtr_rand)
{
    if((mtr_rand->mtr = allocate_matrix(mtr_rand->n, mtr_rand->m)) == NULL)
        return ERROR_MEMORY;

    for (int i = 0; i < mtr_rand->n_zero; i++)
    {   
        int str = rand() % mtr_rand->n;
        int col = rand() % mtr_rand->m;
        if (mtr_rand->mtr[str][col] == 0)
            mtr_rand->mtr[str][col] = 1 + rand() % 100;
        
        else
            i--;
    }

    return EXIT_SUCCESS;
}

