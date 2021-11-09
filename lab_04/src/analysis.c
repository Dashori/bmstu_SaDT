#include "analysis.h"


int analysis(void)
{
    printf("Выберите размер стека - четное число до 5000: ");
    int n;
    if (scanf("%d", &n) != 1 || n < 2 || n % 2 != 0 || n > 5000)
    {
        printf("Неверный размер стека.\n");
        return ERROR_SIZE;
    }
    printf("Количество элементов в правом и левом стеках в массиве равно %d.\n\n", n);
    struct arr_stack array;
    array.size_arr = n;
    array.arr = calloc(array.size_arr, sizeof(double));
    if (!array.arr)
    {  
        printf("Ошибка выделения памяти\n");
        return ERROR_MEMORY;
    }
    array.cur_size = array.size_arr;
    array.count_left = 0;
    array.count_right = array.size_arr;


    clock_t start_r, end_r, res_r = 0;
    clock_t start_l, end_l, res_l = 0;
    clock_t start_list, end_list, res_list = 0;

    double element = 5.234;
    //правый массив
    start_r = clock();
    for (int i = 0; i < n / 2; i++)
    {
        array.arr[array.count_right] = element;
        array.count_right--;
    }
    end_r = clock();
    res_r = end_r - start_r;

    //левый массив
    start_l = clock();
    for (int i = 0; i < n / 2; i++)
    {
        array.arr[array.count_left] = element;
        array.count_left++;
    }

    end_l = clock(); 
    res_l = end_l - start_l;

    
    
    struct list_stack list;
    list.element = malloc(sizeof(struct list_element));
    if (!list.element)
        return ERROR_MEMORY;
    list.element->elem = element;
    list.element->count = 1;

    //список
    start_list = clock();
    for (int i = 0; i < n; i++)
    {

        struct list_element *new_list = NULL;

        new_list = malloc(sizeof(struct list_element));
        if (!new_list)
            return ERROR_MEMORY;

        new_list->count = (list.element->count) + 1;
        new_list->elem = element;
        new_list->next = list.element;
        list.element = new_list;
    }

    end_list = clock();
    res_list = end_list - start_list;


    printf("\nВремя в тактах при заполнении %d элементов: \n", n);
    printf("Левый стек массива | Правый стек массива | Список |\n");
    printf("-------------------|---------------------|--------|\n");
    printf("%*ld | %*ld | %*ld |\n", 18, res_l, 19, res_r, 6, res_list);


    start_l = clock();

    for (int i = 0; i < n / 2; i++)
    {
        array.arr[array.count_left - 1] = 0;
        array.count_left--;
        array.cur_size++;
    }

    end_l = clock();
    res_l = end_l - start_l;


    start_r = clock();

    for (int i = 0; i < n / 2; i++)
    {
        array.arr[array.count_right] = 0;
        array.count_right++;
        array.cur_size++;
    }

    end_r = clock();
    res_r = end_r - start_r;



    start_list = clock();
    
    for (int i = 0; i < n; i++)
    {

        struct list_element *temp = list.element->next;

        if (list.element->next != NULL)
        {
            free(list.element);
            list.element = temp;
        }
        else
            list.element->count = 0;  
    }

    end_list = clock();
    res_list = end_list - start_list;


    printf("\nВремя в тактах при удалении %d элементов из:\n", n);
    printf("Левого стека массива | Правого стек массива | Списка |\n");
    printf("---------------------|----------------------|--------|\n");
    printf("%*ld | %*ld | %*ld |\n", 20, res_l, 20, res_r, 6, res_list);


    size_t arr_n = n * sizeof(double);
    size_t list_n = n * sizeof(struct list_element);
    printf("\nПамять для %d элементов в байтах:\n", n);
    printf("Массив  |  Список |\n");
    printf("--------|---------|\n");
    printf("%*zu  |  %*zu |\n\n", 6, arr_n, 6, list_n);

    // size_t arr_10 = 10 * sizeof(double);
    // size_t list_10 = 10 * sizeof(struct list_element);
    // printf("\nПамять для 10 элементов в байтах:\n");
    // printf("Массив  |  Список |\n");
    // printf("--------|---------|\n");
    // printf("%*zu  |  %*zu |\n", 6, arr_10, 6, list_10);
    // printf("\nПамять для 100 элементов в байтах:\n");
    // printf("Массив  |  Список |\n");
    // printf("--------|---------|\n");
    // printf("%*zu  |  %*zu |\n", 6, 10 * arr_10, 6, 10 * list_10);
    // printf("\nПамять для 1000 элементов в байтах:\n");
    // printf("Массив  |  Список |\n");
    // printf("--------|---------|\n");
    // printf("%*zu  |  %*zu |\n\n", 6, 100 * arr_10, 6, 100 * list_10);
    
    return EXIT_SUCCESS;
}