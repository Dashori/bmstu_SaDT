#include "read_file.h"

int read_table(FILE *f, char *filename, struct flats *flat, size_t *count)
{
    f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;

    *count = 0;
    while (!read_flat(f, &flat[*count]))
        (*count)++;

    fclose(f);

    return EXIT_SUCCESS;
}

int read_flat(FILE *f, struct flats *flat)
{
    if(read_flat_address(f, flat))
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
int read_flat_address(FILE *f, struct flats *flat)
{
    if (fscanf(f, "%s", flat->address.country) != 1)
        return  EXIT_FAILURE;
    if (fscanf(f, "%s", flat->address.city) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%s", flat->address.street) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->address).num_house) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(flat->address).num_flat) != 1)
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

void read_table_key(struct flats *flat, struct keys *key, size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        (key + i)->index = i + 1;
        (key + i)->square = (flat + i)->square;
    }
}
