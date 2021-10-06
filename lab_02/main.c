#include "struct_flats.h"
#include "menu.h"
#include "add_del_flat.h"
#include "read_file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);
    FILE *f = NULL;
    char *filename = "flats.txt";
    int key;
    size_t count;
    struct flats flat_arr[MAX_FLAT];

    read_table(f, filename, flat_arr, &count);

    printf(" COUNT = %zu\n\n", count);
    print();
    if(scanf("%d", &key) != 1)
    {
        printf("Error key, please, try again according the rules\n");
        return ERROR_KEY;
    }
    if (key == 0)
        return EXIT_SUCCESS;

    if (key == 1)
    {
        print_table(flat_arr, count);

    }
    if (key == 2)
    {
        print_rules_add();
        add_flat(f);
    }
    f = fopen("flats.txt","r");

//    secondary.animals = 1;
//    secondary.year = 1900;
//    secondary.count_owners = 8;
//    secondary.last_owners = 3;


//    flats.square = 4;
//    flats.cost_square_meter = 2000;
//    flats.room_number = 5;
//    flats.is_primary = 1;
//    flats.secondary = secondary;

//    printf("year = %d\n",flats.secondary.year);
//    printf("room = %d\n", flats.room_number);

    return EXIT_SUCCESS;

}
