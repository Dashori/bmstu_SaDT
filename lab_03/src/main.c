#include "menu.h"
#include "input.h"

int main(void)
{
    setbuf(stdout, NULL);
    print_rules();
    print_matrix_rules();
    int key;

    printf("Вариант создания матрицы: ");
    if(scanf("%d", &key) != 1 || key > 1 || key < 0) 
    {   
        printf("Неверный параметр выбора матрицы.\n");
        return ERROR_KEY;
    }

    int n = 0, m = 0;
    int error_code = 0;

    if((error_code = read_param(&n, &m)))
    {
        printf("Неверно введены параметры матрицы.\n");
        return error_code;
    }
    switch (key)
    {
        int **MTR;
        int *A;
        int *IA;
        int *JA;
    case(1):
    {
        int n_zero = 0;
        error_code = input_non_zero(&n_zero, n, m);

        if(!error_code)
            error_code = read_matrix(&MTR, n, m, n_zero);
        
        if(!error_code) 
            print_matrix(MTR, n, m);
        else
            return error_code;
        
        create_sparse(MTR, &A, &IA, &JA, n, m, n_zero);
        // create_IA(MTR, IA, JA, n, m, n_zero);
        
        // free_matrix(MTR);

        return error_code;
    }

    default:
        break;
    }
    // read_matrix();
    // print_vector();
    


    return EXIT_SUCCESS;
}