#include "menu.h"

int check_key(int key, struct flats *flat_arr, size_t *count, struct keys *key_arr)
{
    int n = *count;
    if (key == 1)
        print_table(flat_arr, n);

    if (key == 2)
    {
        int error = 0;
        print_rules_add();
        if((error = add_flat(flat_arr, count)))
            return error;
    }
    if (key == 3)
    {
        print_rules_del();
        size_t n = *count;
        int square;
        if ((scanf("%d", &square) != 1) || (square < 1))
        {
            printf("Error square of flat. Please write positive integer\n");
            return EXIT_FAILURE;
        }
        del_flat(flat_arr, count, square);
        if (n == *count)
            printf("No flats with this square.\n");

    }
    if (key == 4)
        find_flats(flat_arr, *count);
    if (key == 5)
    {
        read_table_key(flat_arr, key_arr, *count);
        print_table_key(key_arr, *count);
    }
    if (key == 6)
    {
        read_table_key(flat_arr, key_arr, *count);
        sort_table_key(key_arr, *count);
        print_table_key(key_arr, *count);
    }
    if (key == 7)
    {
        read_table_key(flat_arr, key_arr, *count);
        qsort_table_key(key_arr, *count);
        print_table_key(key_arr, *count);
    }
    if (key == 8)
    {
        sort_table(flat_arr, *count);
        print_table(flat_arr, *count);
    }
    if (key == 9)
    {
        qsort_table(flat_arr, *count);
        print_table(flat_arr, *count);
    }
    if (key == 10)
    {
        read_table_key(flat_arr, key_arr, *count);
        sort_table_key(key_arr, *count);
        sort_table_with_key(flat_arr, *count, key_arr);
    }
    if (key == 11)
    {
        read_table_key(flat_arr, key_arr, *count);
        qsort_table_key(key_arr, *count);
        sort_table_with_key(flat_arr, *count, key_arr);
    }


    return EXIT_SUCCESS;

}

