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
    size_t count = 0;
    int error = 0;
    struct flats flat_arr[MAX_FLAT];

    read_table(f, filename, flat_arr, &count);

    print();
    if(scanf("%d", &key) != 1)
    {
        printf("Error key, please, try again according the rules\n");
        return ERROR_KEY;
    }
    if (key == 0)
        return EXIT_SUCCESS;

    while(!(error = check_key(key, flat_arr, &count)))
    {
        printf("\nChoose key:");
        if(scanf("%d", &key) != 1)
        {
            printf("Error key, please, try again according the rules\n");
            return ERROR_KEY;
        }
        if (key == 0)
            return EXIT_SUCCESS;
    }

    return error;

    return EXIT_SUCCESS;

}
