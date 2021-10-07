#include "read_file.h"


int read_table(FILE *f, char *filename, struct flats *arr_flat, size_t *count)
{
    f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;

    *count = 0;
    while (!read_flat(f, &arr_flat[*count]))
        (*count)++;
    return EXIT_SUCCESS;
}

void print_table(struct flats *arr_flat, size_t count)
{
    printf("|---|---------------|---------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
    printf("| № |    country    |      city     |    street     | house |\
 flat | square | room | 1 meter $ | new | fishing |  year | all tenants| last tenants| pets |\n");
    printf("|---|---------------|---------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
    for (size_t i = 0; i < count; i++)
        print_flat(arr_flat[i], i + 1);


}

int read_flat(FILE *f, struct flats *flat)
{
    if(read_flat_adress(f, flat))
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->square)) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->room_number)) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->cost_square_meter)) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->is_primary)) != 1)
        return EXIT_FAILURE;
    if ((flat->is_primary) == 0)
    {
        if(fscanf(f, "%d", &(flat->primary).is_fishing) != 1)
            return EXIT_FAILURE;
    }
    else
        if(read_secondary(f, flat))
            return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
int read_flat_adress(FILE *f, struct flats *flat)
{
    if (fscanf(f, "%s", flat->adress.country) != 1)
        return  EXIT_FAILURE;
    if (fscanf(f, "%s", flat->adress.city) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%s", flat->adress.street) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->adress).num_house) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->adress).num_flat) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
int read_secondary(FILE *f, struct flats *flat)
{
    if (fscanf(f, "%d", &(flat->primary).secondary.year) != 1)
        return EXIT_FAILURE;
    if (fscanf (f, "%d", &(flat->primary).secondary.all_owners) != 1)
        return EXIT_FAILURE;
    if (fscanf (f, "%d", &(flat->primary).secondary.count_last_owners) != 1)
        return EXIT_FAILURE;
    if (fscanf (f, "%d\n", &(flat->primary).secondary.animals) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;

}

void print_flat(struct flats flat, size_t count)
{
    printf("|%*zu|", 3,  count);
    printf("%*s|", 15, flat.adress.country);
    printf("%*s|", 15, flat.adress.city);
    printf("%*s|", 15, flat.adress.street);
    printf("%*d|", 7,flat.adress.num_house);
    printf("%*d|", 6, flat.adress.num_flat);
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
        if (flat.primary.secondary.animals)
            printf("  +   |\n");
        else
            printf("  -   |\n");


    }

    printf("|---|---------------|---------------|---------------|-------\
|------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
}

