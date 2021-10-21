#include "input.h"

int read_param(int *n, int *m)
{
    printf("Введите количество строк матрицы(от 2 до 5000): ");
    if(scanf("%d", n) != 1)
        return ERROR_READ;

    if (*n < 2 || *n > 5000)
        return ERROR_PARAM;

    printf("Введите количество столбцов матрицы(от 2 до 5000): ");
    if(scanf("%d", m) != 1)
        return ERROR_READ;

    if (*m < 2 || *m > 5000)
        return ERROR_PARAM;

    return EXIT_SUCCESS;
}

int input_non_zero(int *n_zero, int n, int m)
{
    printf("Введите количество ненулевых элементов матрицы: ");
    if (scanf("%d", n_zero) != 1)
    {
        printf("Неверное количество ненулевых элементов матрицы.\n");
        return ERROR_READ;
    }

    if (*n_zero < 0 || *n_zero > n * m)
    {
        printf("Неверное количество ненулевых элементов матрицы.\n");
        return ERROR_PARAM;
    }
    return EXIT_SUCCESS;
}

int **allocate_matrix(int n, int m)
{
    int **matrix;
    matrix = malloc(n * sizeof(int*));
    if (!matrix)
        return NULL;

    int *str;
    str = malloc(n * m * sizeof(int));

    if (!str)
        return NULL;
    
    for(int i = 0; i < n; i++)
        matrix[i] = str + i * m;

    return matrix;
}

void free_matrix(int **MTR)
{
    free(MTR[0]);
    free(MTR);
}

int read_elements(int **MTR, int n, int m, int *n_zero)
{
    int str, col;
    int n_zero_2 = 0;
    int el;

    for(int i = 0; i < (*n_zero); i++)
    {
        printf("\nНумерация строк и столбцов матрицы начинается с 1!\n");
        printf("\nВведите строку для нового элемента (по счёту №%d): " , i + 1);
        if (scanf("%d", &str) != 1 || str < 1 || str > n)
        {
            printf("Неверно введёно число строк матрицы.\n");
            return EXIT_FAILURE;
        }

        printf("Введите столбец для нового элемента: ");
        if (scanf("%d", &col) != 1 || col < 1 || col > m)
        {
            printf("Неверно введёно число столбцов матрицы.\n");
            return EXIT_FAILURE;
        }

        printf("Введите элемент матрицы: ");
        if (scanf("%d", &el) != 1)
        {
            printf("Неверно введён числовой элемент матрицы.\n");
            return EXIT_FAILURE;
        }

        MTR[str - 1][col - 1] = el;     

    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (MTR[i][j] != 0)
                n_zero_2++;
 
    printf("Введено %d ненулевых элементов из %d выбранных\n", n_zero_2, *n_zero);
    *n_zero = n_zero_2;

    return EXIT_SUCCESS;
}

void print_matrix(int **MTR, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", MTR[i][j]);
        printf("\n");
    }
}
void print_arr(int *A, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
}

int *allocate_arr(int n_zero)
{
    int *arr;

    arr = malloc(n_zero * sizeof(int));
    if (arr == NULL)
        return NULL;
    
    return arr;
}

void create_arrays(int **MTR, int *A, int *IA, int *JA, int n, int m)
{
    
    // int count = n_zero - 1;
    // for(int i = m  - 1; i >= 0; i--)
    // {   
    //     for(int j = n - 1; j >= 0; j--)
    //         if (MTR[j][i] != 0)
    //         {
    //             A[count] = MTR[j][i];
    //             IA[count] = j;
    //             count--;
    //         }
    //     JA[count] = count;
    // }
    JA[0] = 0;
    int cur = 0;
    
    for (int i = 0; i < m; i++)
    {
        int count_JA = 0;
        for(int j = 0; j < n; j++)
            if(MTR[j][i] != 0)
            {
                A[cur] = MTR[j][i];
                IA[cur] = j;
                cur++;
                count_JA++;
            } 
        JA[i + 1] = count_JA + JA[i];
    }


}
void create_sparse(int **MTR, int **A, int **IA, int **JA, int n, int m, int n_zero)
{
    *A = allocate_arr(n_zero);
    *IA = allocate_arr(n_zero);
    *JA = allocate_arr(m + 1);

    create_arrays(MTR, *A, *IA, *JA, n, m);

    
    printf("AAA\n");

    print_arr(*A, n_zero);
    printf("BBB\n");
    print_arr(*IA, n_zero);
    printf("CCC\n");
    print_arr(*JA, m + 1);
    printf("\n");
}

int read_matrix(int ***MTR, int n, int m, int n_zero)
{
    
    if(((*MTR) = allocate_matrix(n, m)) == NULL)
        return ERROR_MEMORY;
    
    if (read_elements(*MTR, n, m, &n_zero))
    {
        free_matrix(*MTR);
        return ERROR_ELEMENT;
    }

    return EXIT_SUCCESS;
}

