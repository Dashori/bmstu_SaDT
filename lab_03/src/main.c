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


    while(flag)
    {
        print_menu();
        printf("Выберите пункт меню: ");
        if(scanf("%d", &key) != 1 || key > 8 || key < 0) 
        {   
            printf("Неверный параметр меню.\n");
            return ERROR_KEY;
        }

        if (key == 0)
        {
            printf("Программма успешно завершена по вашему желанию.\n");
            return EXIT_SUCCESS;
        }
                
        error_code = do_actions(key, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, &flag_matrix, &flag_str);
        if (error_code)
            flag = 0;

    }
 
    return error_code;
}