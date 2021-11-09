#include "structs.h"

int allocate_array(struct arr_stack *array)
{
    printf("Введите максимальный размер массива для стека(от 1 до 5000): ");
    if (scanf("%d", &array->size_arr) != 1 || array->size_arr < MIN_SIZE || array->size_arr > MAX_SIZE)
    {
        printf("Введён неверный размер массива для стека.\n");
        return ERROR_SIZE;
    }
    array->arr = calloc(array->size_arr, sizeof(double));
    if (!array->arr)
    {  
        printf("Ошибка выделения памяти\n");
        return ERROR_MEMORY;
    }

    array->cur_size = array->size_arr;
    array->count_left = 0;
    array->count_right = array->size_arr;

    return EXIT_SUCCESS;
}
