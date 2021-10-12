#include "menu.h"

int check_key(int key, struct flats *flat_arr, size_t *count, struct keys *key_arr, char *filename)
{
    int n = *count;
    switch (key)
    {
    case 1:
            print_table(flat_arr, n);
            break;

    case 2:
        {
            int error = 0;
            print_rules_add();
            if((error = add_flat(flat_arr, count, filename, key_arr)))
                return error;
            printf("\nFlat successfully added.\n");
            break;
        }

    case 3:
        {
            if (*count == 0)
            {
                printf("\nYou can't delete flat, because file is empty.\n");
                break;
            }
            print_rules_del();
            size_t n = *count;
            int square;
            if ((scanf("%d", &square) != 1) || (square < 1))
            {
                printf("Error square of flat. Please write positive integer\n");
                return EXIT_FAILURE;
            }
            del_flat(flat_arr, count, square, filename);
            if (n == *count)
                printf("No flats with this square.\n");
            else
                printf("Successfully deleted\n");
            break;
        }

    case 4:
        find_flats(flat_arr, *count);
        break;

    case 5:
        print_table_key(key_arr, *count);
        break;

    case 6:
        sort_table_key(key_arr, *count);
        print_table_key(key_arr, *count);
        break;

    case 7:
        qsort_table_key(key_arr, *count);
        print_table_key(key_arr, *count);
        break;

    case 8:
        sort_table(flat_arr, *count);
        print_table(flat_arr, *count);
        read_table_key(flat_arr, key_arr, *count);
        break;

    case 9:
        qsort_table(flat_arr, *count);
        print_table(flat_arr, *count);
        read_table_key(flat_arr, key_arr, *count);
        break;

    case 10:
        sort_table_key(key_arr, *count);
        sort_table_with_key(flat_arr, *count, key_arr);
        break;

    case 11:
        qsort_table_key(key_arr, *count);
        sort_table_with_key(flat_arr, *count, key_arr);
        break;

    case 12:
        compare_sort(flat_arr, *count, key_arr);
        break;

    default:
        printf("Error key, please, try again according the rules\n");
        return ERROR_KEY;
    }

    return EXIT_SUCCESS;
}
