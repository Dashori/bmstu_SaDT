#include "add_del_flat.h"

int trim(char *s)
{
    if (strlen(s) < 2 || s[strlen(s) - 1] != '\n')
            return EXIT_FAILURE;

    char(*s1) = s + strlen(s) - 1;

    while (isspace(*s1))
        s1--;
    *(s1 + 1) = 0;

    return EXIT_SUCCESS;
}

int add_flat(struct flats *flat_arr, size_t *count, char *filename)
{
    setbuf(stdout, NULL);
    if (*count == MAX_FLAT)
    {
        printf("It is impossible to add an apartment,\
since there are 200 of them at most.");
        return ERROR_MAX_FLAT;
    }

    int n = *count;
    if(add_address(&flat_arr[n].address))
        return ERROR_ADRESS;

    if (add_param_flat(&flat_arr[n]))
        return ERROR_FLAT_PARAM;
    (*count)++;

    FILE *f = fopen(filename, "a");
    add_file(&flat_arr[n], f);
    fclose(f);

    return EXIT_SUCCESS;
}

int add_address(struct address_flat *new_address)
{
    getchar();
    printf("Enter the country: ");
    if ((fgets(new_address->country, MAX_COUNTRY + 1, stdin) == NULL) || (trim(new_address->country)))
    {
        printf("Error country. Please try again according the rules");
        return ERROR_ADRESS;
    }

    printf("Enter the city: ");
    if ((fgets(new_address->city, MAX_CITY + 1, stdin) == NULL) || (trim(new_address->city)))
    {
        printf("Error city. Please try again according the rules");
        return ERROR_ADRESS;
    }
    printf("Enter the street: ");

    if ((fgets(new_address->street, MAX_STREET + 1, stdin) == NULL) || trim(new_address->street))
    {
        printf("Error street. Please try again according the rules");
        return ERROR_ADRESS;
    }
    printf("Enter the number of house: ");
    if (scanf("%d", &new_address->num_house) != 1 || (new_address->num_house < 1))
    {
        printf("Error number of house. Please try again\n");
        return ERROR_ADRESS;
    }

    printf("Enter the number of flat: ");
    if (scanf("%d", &new_address->num_flat) != 1 || (new_address->num_flat < 1))
    {
        printf("Error number of flat. Please try again\n");
        return ERROR_ADRESS;
    }

    return EXIT_SUCCESS;
}

int add_param_flat(struct flats *new_flat)
{
    printf("Enter the square of flat: ");
    if(scanf("%d", &new_flat->square) != 1 || new_flat->square < 1)
    {
        printf("Error square of flat. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter count of room: ");
    if(scanf("%d", &new_flat->room_number) != 1 || new_flat->room_number < 1)
    {
        printf("Error count of room. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter cost of 1 square metr: ");
    if(scanf("%d", &new_flat->cost_square_meter) != 1 || new_flat->cost_square_meter < 1)
    {
        printf("Error value of cost of 1 square metr. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter 0 if flat is new and 1 in another way: ");
    if ((scanf("%d", &new_flat->is_primary) != 1) ||
    (new_flat->is_primary != 0 && new_flat->is_primary != 1))
    {
        printf("Error value about new flat or not. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    if(!new_flat->is_primary)
    {
        printf("Enter 0 if flat with fishing and 1 in another way: ");
        if (scanf("%d", &new_flat->primary.is_fishing) != 1)
        {
            printf("Error value about fishing flat. Please try again.\n");
            return ERROR_FLAT_PARAM;
        }
    }
    else
        if(add_no_primary_flat(new_flat))
            return ERROR_FLAT_PARAM;
    return EXIT_SUCCESS;
}

void add_file(struct flats *flat_arr, FILE *f)
{
    fprintf(f, "%s %s %s %d %d %d %d %d ", flat_arr->address.country, flat_arr->address.city,
    flat_arr->address.street, flat_arr->address.num_house, flat_arr->address.num_flat,
    flat_arr->square, flat_arr->room_number, flat_arr->cost_square_meter);

    if (flat_arr->is_primary)
        fprintf(f, "%d %d %d %d %d\n",flat_arr->is_primary, flat_arr->primary.secondary.year,
    flat_arr->primary.secondary.all_owners, flat_arr->primary.secondary.count_last_owners,
    flat_arr->primary.secondary.animals);
    else
        fprintf(f, "%d %d\n", flat_arr->is_primary, flat_arr->primary.is_fishing);
}

void del_file(struct flats *flat_arr, size_t count, char *filename)
{
    FILE *f = fopen(filename, "w");
    for(size_t i = 0; i < count; i++)
        add_file((flat_arr + i), f);
    fclose(f);
}

int add_no_primary_flat(struct flats *new_flat)
{
    printf("Enter year of construction flat: ");
    if (scanf("%d", &(new_flat->primary).secondary.year) != 1
    || new_flat->primary.secondary.year <= 0 || new_flat->primary.secondary.year > 2021)
    {
        printf("Error year value. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter count of owners of this flat: ");
    if(scanf("%d", &(new_flat->primary).secondary.all_owners) != 1 ||
    new_flat->primary.secondary.all_owners < 0)
    {
        printf("Error count of owners of this flat. Please try again\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter count of last owners: ");
    if ((scanf("%d", &(new_flat->primary.secondary).count_last_owners) != 1)
            || ((new_flat->primary).secondary.count_last_owners < 0))
    {
        printf("Error count of last owners. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter 0 if last owners had animals and 1 in another way: ");
    if((scanf("%d", &(new_flat->primary).secondary.animals) != 1) &&
    (new_flat->primary.secondary.animals != 0 || new_flat->primary.secondary.animals != 1))
    {
        printf("Error information about animals. Please try again.\n");
        return ERROR_FLAT_PARAM;
    }

    return EXIT_SUCCESS;
}

void del_flat(struct flats *flat_arr, size_t *count, int square, char *filename)
{
    for(size_t i = 0; i < *count; i++)
        if ((flat_arr + i)->square == square)
        {
            swap(flat_arr, count, i);
            (*count)--;
        }

    del_file(flat_arr, *count, filename);
}

void swap(struct flats *flat_arr, size_t *count, size_t i)
{
    for(size_t j = i; j < *count - 1; j++)
    {
        (flat_arr + j)->address = (flat_arr + j +1)->address;
        (flat_arr + j)->square = (flat_arr + j +1)->square;
        (flat_arr + j)->room_number = (flat_arr + j +1)->room_number;
        (flat_arr + j)->cost_square_meter = (flat_arr + j +1)->cost_square_meter;
        if (!(flat_arr + j + 1)->is_primary)
            (flat_arr + j)->primary.is_fishing = (flat_arr + j + 1)->primary.is_fishing;
        else
        {
            (flat_arr + j)->primary.secondary.year
                    = ((flat_arr + j + 1)->primary).secondary.year;
            (flat_arr + j)->primary.secondary.all_owners =
                    ((flat_arr + j + 1)->primary).secondary.all_owners;
            (flat_arr + j)->primary.secondary.count_last_owners =
                    ((flat_arr + j + 1)->primary).secondary.count_last_owners;
            (flat_arr + j)->primary.secondary.animals =
                    ((flat_arr + j + 1)->primary).secondary.animals;
        }
        (flat_arr + j)->is_primary = (flat_arr +j + 1)->is_primary;
    }
}
