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
- 3 - ввести строку самостоятельно\n\
- 4 - сгенерировать строку\n\
- 5 - умножить строку на матрицу стандартным методом\n\
- 6 - умножить строку на матрицу в разреженом виде\n\
- 7 - показать сравнение времени для двух способов\n\
- 0 - выход из программы\n");
}

int do_actions(int key, struct matrix_full *mtr, struct sparse_matrix *mtr_spr, 
struct str_matrix *str, struct sparse_matrix *str_spr,
struct str_matrix *res, int *flag_matrix, int *flag_str)
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
        
        printf("\n");
        
        if(!error_code) 
            print_matrix(*mtr);
        else
            return error_code;
        
        error_code = create_sparse_matrix(*mtr, mtr_spr);
        if (error_code)
            return error_code;
        
        (*flag_matrix)++;
        printf("\nМатрица успешно записана\n");
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
        print_matrix(*mtr);

        if (error_code)
            return error_code;

        (*flag_matrix)++;
        printf("\nМатрица успешно записана\n");
        break;
    }
    case(3):
    {
        if(read_param_str(str))
            return ERROR_PARAM;
        
        if((str->mtr = calloc(str->n, sizeof(int))) == NULL)
            return ERROR_MEMORY;

        if(read_element_str(str))
            return ERROR_ELEMENT;
        
        print_str(*str);
        if (error_code)
            return error_code;
        (*flag_str)++;
        printf("\nМатрица-строка успешно записана\n");
        
        break;
    }
    case(4):
    {
        if(read_param_str(str))
            return ERROR_PARAM;

        if(create_rand_str(str))
            return ERROR_MEMORY;

        print_str(*str);
        create_sparse_string(str, str_spr);
        if (error_code)
            return error_code;

        (*flag_str)++;
        printf("\nМатрица-строка успешно записана\n");

        break;
    }
    case(5):
    {
        printf("%d %d\n", *flag_str, *flag_matrix);
        print_matrix(*mtr);

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
 

        multiplicate_matrix(*str, *mtr, res);
        printf("Результат умножения строки на матрицу: \n");
        print_str(*res);

        break;

    }
    default:
        return error_code;
    }

    return EXIT_SUCCESS;
}
