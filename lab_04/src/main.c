#include "print.h"
#include "structs.h"
#include "add_del_arr.h"
#include "add_del_list.h"
#include "analysis.h"

int main(void)
{
    description();
    int error_code = 0;
    int flag = 1;
    int key = 0;
    struct arr_stack array = {0, 0, 0, 0, NULL};
    struct list_stack list;
    list.element = malloc(sizeof(struct list_element));
    if (!list.element)
        return ERROR_MEMORY;
    list.element->next = NULL;
    list.element->count = 0;

    double *free_cells[50];
    size_t len_array = 0;

    while(flag)
    {
        menu();
        if (scanf("%d", &key) != 1 || key < 0 || key > 10)
        {
            printf("Введён неверный ключ.\n");
            return ERROR_KEY;
        }
        switch (key)
        {
        case(0):
            printf("Программа успешно завершена по вашему желанию.\n");
            free(list.element);
            return EXIT_SUCCESS;
        case(1):
        {   
            if (array.size_arr == 0)
                if ((error_code = allocate_array(&array)))
                    return error_code;   

            if (array.cur_size == 0)
            {
                printf("В стеке не осталось места для добавления нового элемента.\n\
Вы можете удалить элементы из стека используя пункты меню.\n\n");
                break;
            }

            if((error_code = add_left(&array)))
                return error_code;
            break;
        }
        case(2):
        {
            if (array.size_arr == 0)
                if ((error_code = allocate_array(&array)))
                    return error_code;   

            if (array.cur_size == 0)
            {
                printf("В стеке не осталось места для добавления нового элемента.\n\
Вы можете удалить элементы из стека используя пункты меню.\n\n");
                break;
            }

            if((error_code = add_right(&array)))
                return error_code;
            break;
        }
        case(3):
            del_left(&array);
            break;
        case(4):
            del_right(&array);
            break;
        case(5):
            print_info_arr(array);
            break;
        case(6):
            if (list.element->count == MAX_SIZE)
            {
                printf("Невозможно добавить элемент в стек, так как он переполнен.\n");
                break;
            }
            if ((error_code = allocate_el_list(&list)))
                return error_code;
            break;
        case(7): 
            if(!list.element->count)
                printf("\nНевозможно удалить элемент из стека, так как он пуст.\n\n");
            else   
                pop_list_element(&list, free_cells, &len_array);
            break;
        case(8):
            if(!list.element->count)
                printf("\nНевозможно вывести стек, так как он пуст.\n\n");
            else
                print_list(list);
            break;
        case(9):
            if(!len_array)
                printf("\nНевозможно вывести массив свободных ячеек, так как он пуст.\n\n");
            else
                print_free_list(free_cells, len_array);
            break;
        case(10):
            if ((error_code = analysis()))
                return error_code;
            break;
        default:
            break;
        }            
    }
    
    return EXIT_SUCCESS;
}