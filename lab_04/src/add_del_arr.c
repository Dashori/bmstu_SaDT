#include "add_del_arr.h"

int add_left(struct arr_stack *array)
{
    printf("Введите элемент левого стека(осталось %d мест): ", array->cur_size);
    if (scanf("%lf", &array->arr[array->count_left]) != 1)
    {
        printf("Неверный элемент стека.\n");
        return ERROR_ELEMENT_ARR;
    }
    array->count_left++;
    array->cur_size--;
    printf("\nЭлемент успешно добавлен в стек.\n");

    return EXIT_SUCCESS;
}

int add_right(struct arr_stack *array)
{
    printf("Введите элемент правого стека(осталось %d мест): ", array->cur_size);
    if (scanf("%lf", &array->arr[array->count_right - 1]) != 1)
    {
        printf("Неверный элемент стека.\n");
        return ERROR_ELEMENT_ARR;
    }
    array->count_right--;
    array->cur_size--;
    printf("\nЭлемент успешно добавлен в стек.\n");

    return EXIT_SUCCESS;
}

void del_left(struct arr_stack *array)
{
    if (array->count_left == 0)
        printf("\nНевозможно удалить элементы из стека, ибо он пуст.\n\n");
    else
    {
        printf("Элемент левого стека %lf успешно удален.\n\n", array->arr[array->count_left - 1]);
        array->arr[array->count_left - 1] = 0;
        array->count_left--;
        array->cur_size++;
    }
}

void del_right(struct arr_stack *array)
{
    if (array->count_right == array->size_arr)
        printf("\nНевозможно удалить элементы из стека, ибо он пуст.\n\n");
    else
    {
        printf("Элемент правого стека %lf успешно удален.\n\n", array->arr[array->count_right]);
        array->arr[array->count_right] = 0;
        array->count_right++;
        array->cur_size++;
    }
}
