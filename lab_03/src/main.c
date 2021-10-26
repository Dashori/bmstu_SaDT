#include "menu.h"

int main(void)
{
    setbuf(stdout, NULL);
    print_rules();
    int key;
    int flag = 1;
    int error_code = 0;

    struct matrix_full mtr;
    struct sparse_matrix mtr_spr;
    struct str_matrix str;
    struct sparse_matrix str_spr;
    struct str_matrix res;
    struct sparse_matrix res_spr;

    int flag_matrix = 0;
    int flag_str = 0;
    int flag_mult = 0;
    int flag_mult_spr = 0;
    int flag_compare = 0;

    clock_t res_time = 0;
    clock_t res_time_spr = 0;


    while(flag)
    {
        print_menu();
        printf("Выберите пункт меню: ");
        if(scanf("%d", &key) != 1 || key > 9 || key < 0) 
        {   
            printf("Неверный параметр меню.\n");
            return ERROR_KEY;
        }

        if (key == 0)
        {
            if (flag_str)
            {
                free_arr(mtr_spr.IA);
                free_arr(mtr_spr.JA);
                free_arr(mtr_spr.A);
            }
            if (flag_matrix)
            {
                free_matrix(mtr.mtr);
            }
            printf("Программма успешно завершена по вашему желанию.\n");
            return EXIT_SUCCESS;
        }

        if(key == 9)
        {
            flag_compare = 1;
            error_code = do_actions(7, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);
            if(!error_code)
                error_code = do_actions(8, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);
            flag_compare = 0;
        }
                
        error_code = do_actions(key, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);

    }
 
    return error_code;
}
