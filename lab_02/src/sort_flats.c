#include "sort_flats.h"

int compare(const void *a, const void *b)
{
    return (((struct keys *)a)->square - ((struct keys *)b)->square);
}

int compare_square(const void *a, const void *b)
{
    return (((struct flats *)a)->square - ((struct flats *)b)->square);
}

void sort_table_key(struct keys *key, size_t count)
{
    for (size_t i = 0; i < count; i++)
        for(size_t j = 0;  j < count - 1; j++)
            if((key + j)->square > (key + j + 1)->square)
            {
                int temp = (key + j)->square;
                (key + j)->square = (key + j + 1)->square;
                (key + j + 1)->square = temp;
                int id = (key + j)->index;
                (key + j)->index = (key + j + 1)->index;
                (key + j + 1)->index = id;
            }
}

void qsort_table_key(struct keys *key, size_t count)
{
    qsort(key, count, sizeof(struct keys), compare);
}

void sort_table_with_key(struct flats *flat, size_t count, struct keys *key)
{
    print_table_rama();
    for(size_t i = 0; i < count ; i++)
        print_flat(*(flat  - 1 + ((key + i)->index)), i + 1);
}

void swap_sort(struct flats *flat_arr, size_t count)
{
    struct flats temp[count];
    memcpy(temp, flat_arr, sizeof(struct flats));
    memcpy(flat_arr, (flat_arr + 1), sizeof(struct flats));
    memcpy((flat_arr + 1), temp, sizeof(struct flats));
}

void sort_table(struct flats *flat, size_t count)
{
    size_t n = count;
    for(size_t i = 0; i < count; i++)
        for(size_t j = 0; j < count - 1; j++)
            if ((flat + j)->square > (flat + j + 1)->square)
                swap_sort(flat + j, n);
}

void qsort_table(struct flats *flat, size_t count)
{
    qsort(flat, count, sizeof(struct flats), compare_square);
}
