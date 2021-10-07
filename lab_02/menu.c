#include "menu.h"

int check_key(int key, struct flats *flat_arr, size_t *count)
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
        if (scanf("%d", &square) != 1)
            return EXIT_FAILURE;
        del_flat(flat_arr, count, square);
        if (n == *count)
            printf("No flats with this square.\n");

    }
    return EXIT_SUCCESS;

}
void print(void)
{
    printf("\nThis programm can show you the tables with flats and sort thoose tables\n\
What you can do with a key:\n\n\
0 - EXIT\n\
1 - Show flat table\n\
2 - Add flat\n\
3 - Delete flat\n\
4 - Show key table\n\
5 - Show all secondary flat with 2 rooms and animals\n\
6 - Show all primary flat with 3 rooms and 100+ square\n\n\
Choose key:");
}

void print_rules_add(void)
{
    printf("\nWhen you enter the flat to table:\n\
The city, street and country should be written in one word.\n\
Enter number of house and flat without spaces and letters\n\
\n\r");
}

void print_rules_del(void)
{
    printf("\nEnter the square of flats, that you want to delete:");
}
