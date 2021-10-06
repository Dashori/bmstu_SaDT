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
    for (size_t i = 0; i < count; i++)
        print_flat(arr_flat[i]);
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

void print_flat(struct flats flat)
{
    printf("country: %s\n", flat.adress.country);
    printf("city: %s\n", flat.adress.city);
    printf("street: %s\n", flat.adress.street);
    printf("num house: %d\n",flat.adress.num_house);
    printf("num flat: %d\n", flat.adress.num_flat);
    printf("square: %d\n", flat.square);
    printf("room number: %d\n", flat.room_number);
    printf("cost of 1 square meter: %d\n", flat.cost_square_meter);
    printf("is primary: %d\n", flat.is_primary);

    if (flat.is_primary == 0)
        printf("fishing: %d\n\n",flat.primary.is_fishing);
    else
    {
        printf("year: %d\n", flat.primary.secondary.year);
        printf("all oweners: %d\n", flat.primary.secondary.all_owners);
        printf("count last owners: %d\n", flat.primary.secondary.count_last_owners);
        printf("animals: %d\n\n", flat.primary.secondary.animals);
    }
}

