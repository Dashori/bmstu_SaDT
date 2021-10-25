#include "menu.h"

void print_rules(void)
{
    printf("\nДанная программа способна умножать матрицу на строку.\n\
При этом матрица и строка могут храниться как в обычном формате,\n\
так и в разреженном(без нулей).\n\n\
Разреженная (содержащая много нулей) матрица хранится в форме 3-х объектов:\n\
-вектор A содержит значения ненулевых элементов\n\
-вектор IA содержит номера строк для элементов вектора A\n\
-вектор JA, в элементе Nk которого находится номер компонентв A и IA,\n\
с которых начинается описание столбца Nk матрицы A.\n\n");
}

void print_menu(void)
{
    printf("Пункты меню:\n\
- 1 - ввести матрицу самостоятельно\n\
- 2 - сгенерировать матрицу\n\
- 3 - распечатать матрицу\n\
- 4 - ввести строку самостоятельно\n\
- 5 - сгенерировать строку\n\
- 6 - распечатать строку\n\
- 7 - умножить строку на матрицу стандартным методом\n\
- 8 - умножить строку на матрицу в разреженом виде\n\
- 9 - показать сравнение времени для двух способов\n\
- 0 - выход из программы\n");
}

int do_actions(int key, struct matrix_full *mtr, struct sparse_matrix *mtr_spr, 
struct str_matrix *str, struct sparse_matrix *str_spr,
struct str_matrix *res, struct sparse_matrix *res_spr, int *flag_matrix, int *flag_str, 
int *flag_mult, int *flag_mult_spr, clock_t *res_time, clock_t *res_time_spr)
{
    int error_code = 0;
    switch (key)
    {
    case(1):
    {
        if((error_code = read_param(mtr)))
        {
            printf("Неверно введены параметры матрицы.\n");
            return error_code;
        }

        error_code = input_non_zero(mtr);

        if(!error_code)
            error_code = read_matrix(mtr);
        
        if(!error_code) 
            error_code = create_sparse_matrix(*mtr, mtr_spr);

        if (error_code)
            return error_code;
        
        (*flag_matrix)++;
        printf("\nМатрица успешно записана,\n\n");
        break;
    }
    case(2):
    {
        if((error_code = read_param(mtr)))
        {
            printf("Неверно введены параметры матрицы.\n");
            return error_code;
        }
  
        error_code = input_non_zero(mtr);

        if (!error_code)
            if(create_rand_matrix(mtr))
                return ERROR_MEMORY;

        if(!error_code)
            error_code = create_sparse_matrix(*mtr, mtr_spr);

        if (error_code)
            return error_code;

        (*flag_matrix)++;
        printf("\nМатрица успешно записана.\n\n");
        break;
    }
    case(3):
    {
        if (!*flag_matrix)
        {
            printf("\nНевозможно распечатать матрицу, она ещё не введена.\n\n");
            break;
        }
        printf("Форматы вывода матрицы: \n\
- 1 - В стандартном виде\n\
- 2 - В разреженном виде\n\
Выберите формат вывода матрицы на экран: ");
        int type;
        if (scanf("%d", &type) != 1 || type < 1 || type > 2)
        {
            printf("Неверно введен формат вывода матрицы\n");
            break;
        }
        if (type == 1)
            print_matrix(*mtr);
        else
        {
            printf("A: ");
            print_arr(mtr_spr->A, mtr->n_zero);
            printf("IA: ");
            print_arr(mtr_spr->IA, mtr->n_zero);
            printf("JA: ");
            print_arr(mtr_spr->JA, mtr->m + 1);
        }

        break;
    }
    case(4):
    {
        if(read_param_str(str))
            return ERROR_PARAM;
        
        if((str->mtr = calloc(str->n, sizeof(int))) == NULL)
            return ERROR_MEMORY;

        if(read_element_str(str))
            return ERROR_ELEMENT;
        
        if(create_sparse_string(*str, str_spr))
            return ERROR_MEMORY;

        (*flag_str)++;
        printf("\nМатрица-строка успешно записана.\n\n");
        
        break;
    }
    case(5):
    {
        if(read_param_str(str))
            return ERROR_PARAM;

        if(create_rand_str(str))
            return ERROR_MEMORY;

        if(create_sparse_string(*str, str_spr))
            return ERROR_MEMORY;

        (*flag_str)++;
        printf("\nМатрица-строка успешно записана.\n\n");

        break;
    }
    case(6):
    {
        if (!*flag_str)
        {
            printf("\nНевозможно распечатать строку, она ещё не введена.\n\n");
            break;
        }
        printf("Форматы вывода строки: \n\
- 1 - В стандартном виде\n\
- 2 - В разреженном виде\n\
Выберите формат вывода строки на экран: ");
        int type;
        if (scanf("%d", &type) != 1 || type < 1 || type > 2)
        {
            printf("Неверно введен формат вывода строки\n");
            break;
        }
        if (type == 1)
            print_str(*str);
        else
        {
            printf("A: ");
            print_arr(str_spr->A, str->n_zero);
            printf("IA: ");
            print_arr(str_spr->IA, str->n_zero);
            printf("JA: ");
            print_arr(str_spr->JA, str->n + 1);
        }

        break;
    }
    case(7):
    {
        if (!*flag_str)
        {
            printf("\nНевозможно выполнить умножение, так как не введена матрица-строка.\n\n");
            break;
        }
        if (!*flag_matrix)
        {
            printf("\nНевозможно выполнить умножение, так как не введена матрица.\n\n");
            break;
        }
        if (str->n != mtr->n)
        {
            printf("\nНевозможно умножить строку на матрицу, так как размер строки \n\
не совпадает с количеством строк матрицы\n\n");
            return ERROR_MULTI;
        }
      
        if((res->mtr = calloc(mtr->m, sizeof(int))) == NULL)
            return ERROR_MEMORY;
        res->n = mtr->m;
 

        multiplicate_matrix(*str, *mtr, res, res_time);
        printf("Результат умножения строки на матрицу: \n");
        print_str(*res);

        (*flag_mult)++;

        break;

    }
    case(8):
    {
        if (!*flag_str)
        {
            printf("\nНевозможно выполнить умножение, так как не введена матрица-строка.\n\n");
            break;
        }
        if (!*flag_matrix)
        {
            printf("\nНевозможно выполнить умножение, так как не введена матрица.\n\n");
            break;
        }
        if (str->n != mtr->n)
        {
            printf("\nНевозможно умножить строку на матрицу, так как размер строки \n\
не совпадает с количеством строк матрицы\n\n");
            return ERROR_MULTI;
        }

        if ((res_spr->A = allocate_arr(mtr->n_zero)) == NULL)
            return ERROR_MEMORY;
        if ((res_spr->IA = allocate_arr(mtr->n_zero)) == NULL)
            return ERROR_MEMORY;
        if ((res_spr->JA = allocate_arr(mtr->m + 1)) == NULL)
            return ERROR_MEMORY;
        
        multiplicate_sparse(*str_spr, *mtr_spr, res_spr, res_time_spr);

        printf("\nРезультат умножения строки на матрицу в разреженном виде: \n");
        printf("A: ");
        print_arr(res_spr->A, res_spr->col);
        printf("IA: ");
        print_arr(res_spr->IA, res_spr->col);
        printf("JA: ");
        print_arr(res_spr->JA, mtr->m + 1);

        (*flag_mult_spr)++;

        break;
    }
    default:
        return error_code;
    }

    return EXIT_SUCCESS;
}
