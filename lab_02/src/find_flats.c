#include "find_flats.h"

int find_flats(struct flats *arr_flats, size_t count)
{
    int lower, upper;
    printf("\nEnter the lower border of the price of 1 square meter - positive integer: ");
    if ((scanf("%d", &lower) != 1) || lower < 1)
    {
        printf("Error lower price of 1 square meter. Please try again\n");
        return ERROR_PRICE;
    }
    printf("Enter the upper border of the price of 1 square meter - positive integer: ");
    if ((scanf("%d", &upper) != 1) || upper < 1)
    {
        printf("Error upper price of 1 square meter. Please try again\n");
        return ERROR_PRICE;
    }

    printf("Table of all non-new 2-room flats in which people lived with pets.\n");
    printf("Lower price is: %d\n", lower);
    printf("Upper price is: %d\n\n", upper);
    print_table_rama();

    int flag = 0;
    size_t n = 1;
    for (size_t i = 0; i < count; i++)
        if (((arr_flats + i)->room_number == 2) &&
            ((arr_flats + i)->is_primary) &&
            !((arr_flats + i)->primary.secondary.animals) &&
            ((arr_flats + i)->cost_square_meter) <= upper &&
            ((arr_flats + i)->cost_square_meter >= lower))
        {
            flag = 1;
            print_flat(*(arr_flats + i), n++);
        }
    if (!flag)
    {
        printf("|                                                          there are no necessary apartments\
                                                              |\n");
        printf("|---|---------------|----------------|---------------|-------\
|------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");

    }
    return EXIT_SUCCESS;
}
