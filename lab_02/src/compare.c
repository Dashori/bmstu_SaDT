#include "compare.h"

void compare_sort(struct flats *flat, size_t count, struct keys *key)
{
    clock_t start_b, end_b, start_b_key, end_b_key;
    clock_t res_b = 0, res_b_key = 0;
    struct keys key_b[count];
    struct flats flat_b[count];

    for(int i = 0; i < 1000; i++)
    {
        memcpy(key_b, key, sizeof(struct keys) * count);
        start_b_key = clock();
        qsort_table_key(key_b, count);
        end_b_key = clock();
        res_b_key += (end_b_key - start_b_key);

        memcpy(flat_b, flat, sizeof(struct flats) * count);
        start_b = clock();
        sort_table(flat_b, count);
        end_b = clock();
        res_b += (end_b - start_b);


    }
    printf("\nBubble sort table:    %lf\n", (double)res_b);
    printf("Bubble sort key table:  %lf\n", (double)res_b_key);

    clock_t start_q, end_q, start_q_key, end_q_key;
    clock_t res_q = 0, res_q_key = 0;

    struct keys key_q[MAX_FLAT];
    struct flats flat_q[MAX_FLAT];

    for(int i = 0; i < 1000; i++)
    {
        memcpy(flat_q, flat, sizeof (struct flats) * count);
        start_q = clock();
        qsort_table(flat_q, count);
        end_q = clock();
        res_q += (end_q - start_q);

        memcpy(key_q, key, sizeof (struct keys) * count);
        start_q_key = clock();
        qsort_table_key(key_q, count);
        end_q_key = clock();
        res_q_key += (end_q_key - start_q_key);
    }

    printf("\nQsort table:     %lf\n", (double)res_q);
    printf("Qsort table key:   %lf\n", (double)res_q_key);

    size_t size_key = sizeof (struct keys) * count;
    size_t size_tab = sizeof (struct flats) * count;
    printf("\nSize of memory with key table: %zu", size_key);
    printf("\nSize  of  memory  with  table: %zu\n", size_tab);


}
