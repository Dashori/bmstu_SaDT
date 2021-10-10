#include "sort_flats.h"

int compare(const void *a, const void *b)
{
    return (((struct keys *)a)->square - ((struct keys *)b)->square);
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
    qsort(key, count, sizeof (struct keys), compare);
}

void sort_table_with_key(struct flats *flat, size_t count, struct keys *key)
{
    print_table_rama();
    for(size_t i = 0; i < count ; i++)
        print_flat(*(flat  - 1 + ((key + i)->index)), i + 1);
}


void swap_sort(struct flats *flat_arr)
{
    struct flats temp;
    temp = *flat_arr;
    *(flat_arr) = *(flat_arr + 1);
    *(flat_arr + 1) = temp;
}

void sort_table(struct flats *flat, size_t count)
{
    for(size_t i = 0; i < count; i++)
        for(size_t j = 0; j < count - 1; j++)
            if ((flat + j)->square > (flat + j + 1)->square)
                swap_sort(flat + j);

}

void qsort_table(struct flats *flat, size_t count)
{
    qsort(flat, count, sizeof (struct keys), compare);
}
