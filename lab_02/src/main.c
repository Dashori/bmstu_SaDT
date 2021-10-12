#include "struct_flats.h"
#include "menu.h"
#include "add_del_flat.h"
#include "read_file.h"
#include "print.h"
#include "compare.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);
    FILE *f = NULL;
    char *filename = "./data/flats40.txt";
    int key;
    size_t count = 0;
    int error = 0;

    struct flats flat_arr[MAX_FLAT + 1];
    struct keys key_arr[MAX_FLAT + 1];

    if(read_table(f, filename, flat_arr, &count))
        return EXIT_FAILURE;

    read_table_key(flat_arr, key_arr, count);
    print_info();
    print();


    if(scanf("%d", &key) != 1)
    {
        printf("\nError key, please, try again according the rules\n");
        return ERROR_KEY;
    }
    if (key == 0)
        return EXIT_SUCCESS;

    while(!(error = check_key(key, flat_arr, &count, key_arr, filename)))
    {
        print();
        if(scanf("%d", &key) != 1)
        {
            printf("\nError key, please, try again according the rules\n");
            return ERROR_KEY;
        }
        if (key == 0)
            return EXIT_SUCCESS;
    }
    return error;

}
