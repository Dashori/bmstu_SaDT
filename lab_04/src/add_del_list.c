#include "add_del_list.h"

 
int allocate_el_list(struct list_stack *list)
{
    double num;
    
    printf("Введите элемент стека под номером %d : ", (list->element->count) + 1);
    if (scanf("%lf", &num) != 1)
    {
        printf("Неверный элемент стека.\n");
        return ERROR_ELEMENT_LIST;
    }
    if (list->element->count == 0)
    {
        list->element->elem = num;
        list->element->count = 1;
        return EXIT_SUCCESS;
    }

    struct list_element *new_list = NULL;
    new_list = malloc(sizeof(struct list_element));
    if (!new_list)
        return ERROR_MEMORY;

    new_list->count = (list->element->count) + 1;
    new_list->elem = num;
    new_list->next = list->element;
    list->element = new_list;
    
    return EXIT_SUCCESS;
}

void free_element(struct list_element *element)
{
    free(element);
}

void pop_list_element(struct list_stack *list, double *array[50], size_t *len_array)
{
    printf("Удаление элемента: %lf\n", list->element->elem);
    array[*len_array] = &list->element->elem; 
    // printf(" %p ", (list->element->;
    // printf(" %p ", (void*)array[*len_array]);
    (*len_array)++;
    struct list_element *temp = list->element->next;

    if (list->element->next != NULL)
    {
        free(list->element);
        list->element = temp;
        printf(" count = %d\n", list->element->count);
    }
    else
        list->element->count = 0;   
}
