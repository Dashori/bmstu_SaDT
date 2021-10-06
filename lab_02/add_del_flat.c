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

int add_flat(FILE *f)
{
    setbuf(stdout, NULL);
    f = fopen("flats.txt", "a");
    if (f == NULL)
        return ERROR_NO_FILE;

    struct flats new_flat;
    struct adress_flat new_adress;

    fgets(new_adress.country, MAX_COUNTRY, stdin);
    printf("Enter the country: ");
    if ((fgets(new_adress.country, MAX_COUNTRY + 1, stdin) == NULL) || (trim(new_adress.country)))
    {
        printf("Error country. Please try again according the rules");
        fclose(f);
        return EXIT_FAILURE;
    }
    printf("Enter the city: ");
    if ((fgets(new_adress.city, MAX_CITY + 1, stdin) == NULL) || (trim(new_adress.city)))
    {
        printf("Error city. Please try again according the rules");
        fclose(f);
        return EXIT_FAILURE;
    }
    printf("Enter the street: ");
    if ((fgets(new_adress.street, MAX_STREET + 1, stdin) == NULL) || trim(new_adress.street))
    {
        printf("Error street. Please try again according the rules");
        fclose(f);
        return EXIT_FAILURE;
    }
    printf("Enter the number of house: ");
    if (scanf("%d", &new_adress.num_house) != 1)
    {
        printf("Error number of house. Please try again\n");
        fclose(f);
        return ERROR_ADRESS;
    }
    printf("Enter the number of flat:");
    if (scanf("%d", &new_adress.num_flat) != 1)
    {
        printf("Error number of flat. Please try again\n");
        fclose(f);
        return ERROR_ADRESS;
    }

    printf("Enter the square of flat: ");
    if(scanf("%d", &new_flat.square) != 1)
    {
        printf("Error square of flat. Please try again\n");
        fclose(f);
        return ERROR_FLAT_PARAM;
    }

    printf("Enter count of room:");
    if(scanf("%d", &new_flat.room_number) != 1)
    {
        printf("Error count of room. Please try again\n");
        fclose(f);
        return ERROR_FLAT_PARAM;
    }
    printf("Enter cost of 1 square metr: ");

    if(scanf("%d", &new_flat.cost_square_meter) != 1)
    {
        printf("Error value of cost of 1 square metr. Please try again\n");
        fclose(f);
        return ERROR_FLAT_PARAM;
    }

    printf("Enter 0 if flat is new and 1 in another way: ");
    if ((scanf("%d", &new_flat.is_primary) != 1) ||
(new_flat.is_primary != 0 && new_flat.is_primary != 1))
    {
        printf("Error value about new flat or not. Please try again\n");
        fclose(f);
        return ERROR_FLAT_PARAM;
    }

    if(!new_flat.is_primary)
    {
        printf("Enter 0 if flat with fishing and 1 in another way: ");
        if (scanf("%d", &new_flat.primary.is_fishing) != 1)
        {
            printf("Error value about fishing flat. Please try again\n");
            fclose(f);
            return ERROR_FLAT_PARAM;
        }
    }
    else
    {
        if(add_no_primary_flat(&new_flat))
            return ERROR_FLAT_PARAM;

    }

    fprintf(f, "\n%s %s %s %d %d %d %d %d ", new_adress.country, new_adress.city,
    new_adress.street, new_adress.num_house, new_adress.num_flat, new_flat.square, new_flat.room_number,
    new_flat.cost_square_meter);

    if (new_flat.is_primary)
        fprintf(f, "%d %d %d %d %d\n",new_flat.is_primary, new_flat.primary.secondary.year,
    new_flat.primary.secondary.all_owners, new_flat.primary.secondary.count_last_owners,
    new_flat.primary.secondary.animals);
    else
        fprintf(f, "%d %d", new_flat.is_primary, new_flat.primary.is_fishing);

    fclose(f);

    return EXIT_SUCCESS;
}
int add_no_primary_flat(struct flats *new_flat)
{
    printf("Enter year of construction flat: ");

    if (scanf("%d", &(new_flat->primary).secondary.year) != 1
|| new_flat->primary.secondary.year <= 0 || new_flat->primary.secondary.year > 2021)
    {
        printf("Error year value. Please try again\n");
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
    if ((scanf("%d", &(new_flat->primary.secondary).count_last_owners) != 1) || ((new_flat->primary).secondary.count_last_owners < 0))
    {
        printf("Error count of last owners. Please try again\n");
        return ERROR_FLAT_PARAM;
    }

    printf("Enter 0 if last owners had animals and 1 in another way: ");
    if((scanf("%d", &(new_flat->primary).secondary.animals) != 1) &&
(new_flat->primary.secondary.animals != 0 || new_flat->primary.secondary.animals != 1))
    {
        printf("Error information about animals. Please try again\n");
        return ERROR_FLAT_PARAM;
    }

    return EXIT_SUCCESS;
}

