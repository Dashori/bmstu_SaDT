#include "print.h"

void description(void)
{
    printf("\nДанная программа реализует стек для действительных чисел с помощью:\n\
- массива, который содержит два стека:\n\
    -один идет с начала массива к его концу\n\
    -второй идет с конца массива к его началу\n\
- связного спика\
Максимальное количество элементов в стеках - 5000\n");
}
void menu(void)
{
    printf("Пунты меню:\n\
Для массива:\n\
1 - добавить элемент в левый стек\n\
2 - добавить элемент в правый стек\n\
3 - удалить элемент в левом стеке\n\
4 - удалить элемент в правом стеке\n\
5 - посмотреть текущее состояние стеков в массиве\n\n\
Для списка:\n\
6 - добавить элемент в стек\n\
7 - удалить элемент в стеке\n\
8 - посмотреть текущее состояние списка\n\
9 - посмотреть массив адресов, в которых хранились элементы\n\n\
10 - посмотреть сравнение реализации двух подходов\n\
0 - выйти из программы\n\n\
Введите ключ: ");
}

void print_arr(struct arr_stack array)
{
    printf("\nЛевый стек:\n");
    if(array.count_left == 0)
        printf("Левый стек пуст.\n");
    else
    {
        for (int i = 0; i < array.count_left; i++)
            printf("%lf ", array.arr[i]);
        printf("\n");
    }
    printf("\nПравый стек:\n");
    if(array.count_right == array.size_arr)
        printf("Правый стек пуст.\n\n");
    else
    {
        for (int i = array.size_arr - 1; i >= array.count_right; i--)
            printf("%lf ", array.arr[i]);
        printf("\n\n");
    }
}

void print_info_arr(struct arr_stack array)
{
    printf("В массиве из %d элементов свободно %d мест.\n\n", array.size_arr, array.cur_size);
    print_arr(array);
}

void print_list(struct list_stack list)
{
    printf("Всего элементов: %d\n", list.element->count);
    struct list_element *temp = list.element;
    while (temp != NULL)
    {
        printf("Адрес элемента: %p\n", (void*)temp);
        printf("Элемент: %lf\n", temp->elem);
        temp = temp->next;
    }
}

void print_free_list(double *array[50], size_t len_array)
{
    printf("Массив свободных ячеек:\n");
    for(size_t i = 0; i < len_array; i++)
        printf("%p\n", (void*)array[i]);
}