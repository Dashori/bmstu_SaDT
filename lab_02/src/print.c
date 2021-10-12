#include "print.h"

void print_table_rama()
{
    printf("|---|---------------|----------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
    printf("| № |    country    |      city      |    street     | house |\
 flat | square | room | 1 meter $ | new | fishing |  year | all tenants| last tenants| pets |\n");
    printf("|---|---------------|----------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
}

void print_table(struct flats *flat, size_t count)
{
    print_table_rama();
    for (size_t i = 0; i < count; i++)
        print_flat(flat[i], i + 1);
}

void print_table_key(struct keys *key_arr, size_t count)
{
    printf("|---|--------|--------|\n");
    printf("| № | index  | square |\n");
    printf("|---|--------|--------|\n");
    for(size_t i = 0; i < count; i++)
    {
        printf("|%*zu|", 3, i + 1);
        printf("%*d|", 8, (key_arr + i)->index);
        printf("%*d|\n", 8, (key_arr + i)->square);
        printf("|---|--------|--------|\n");
    }
}

void print_flat(struct flats flat, size_t count)
{
    printf("|%*zu|", 3,  count);
    printf("%*s|", 15, flat.address.country);
    printf("%*s|", 16, flat.address.city);
    printf("%*s|", 15, flat.address.street);
    printf("%*d|", 7,flat.address.num_house);
    printf("%*d|", 6, flat.address.num_flat);
    printf("%*d|", 8, flat.square);
    printf("%*d|", 6, flat.room_number);
    printf("%*d|", 11, flat.cost_square_meter);
    if (!flat.is_primary)
    {
        printf("%s|", "  +  ");
        if (flat.primary.is_fishing)
            printf("%s|","    -    ");
        else
            printf("%s|", "    +    ");
        printf("       |            |             |      |\n");
    }
    else
    {
        printf("%s|", "  -  ");
        printf("%s|","         ");
        printf("%*d|",7, flat.primary.secondary.year);
        printf("%*d|",12, flat.primary.secondary.all_owners);
        printf("%*d|",13,flat.primary.secondary.count_last_owners);
        if (!flat.primary.secondary.animals)
            printf("  +   |\n");
        else
            printf("  -   |\n");


    }

    printf("|---|---------------|----------------|---------------|-------\
|------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
}

void print_info(void)
{
    printf("\nThis programm can show you the tables with flats and sort thoose tables\n\
What you can do with a key:\n\n");
}

void print(void)
{
    printf("\n\
0 - EXIT\n\
1 - Show flat table\n\
2 - Add flat\n\
3 - Delete flat\n\
4 - Show all secondary flat with 2 rooms and animals\n\
5 - Show table key by square\n\
6 - Show sort table key by square (bubble sort)\n\
7 - Show sort table key by square (quick sort)\n\
8 - Show sort table be square (bubble sort)\n\
9 - Show sort table by square (quick sort)\n\
10 - Show sort table by square with table (bubble sort)\n\
11 - Show sort table by square with table (quick sort)\n\
12 - Compare time for bubble sort/qsort and table/table_key \n\
Choose key: ");
}

void print_rules_add(void)
{
    printf("\nWhen you enter the flat to table:\n\
The city, street and country should be written in one word and max len is 15 symbols.\n\
Parametrs of flat are integer numbers.\
Please enter them without spaces and letters.\n\n");
}

void print_rules_del(void)
{
    printf("\nEnter the square of flats, that you want to delete:");
}
