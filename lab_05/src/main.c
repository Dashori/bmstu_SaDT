#include "print.h"
#include "exceptions.h"
#include "structs.h"
#include "array.h"
#include "list.h"

int main(void)
{
    description();
    int flag = 1, key;
    struct mem_slot *mem = NULL;
    int mem_used = 0;
    srand(time(NULL));

    while(flag)
    {
        menu();
        if (scanf("%d", &key) != 1 || key < 0 || key > 4)
        {
            printf("Введён неверный ключ.\n");
            return ERROR_KEY;
        }
        switch (key)   
        {
            case(0):
                printf("Программа успешно завершена по вашему желанию.\n");
                return EXIT_SUCCESS;
            case(1):
                simulate_service_arr(&mem_used);
                break;
            case (2):
                simulate_service(&mem, &mem_used);
                break;
            case (3):
                show_mem(&mem);
                break;
            case (4):
                queue_compare(&mem);
                break;      
            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}