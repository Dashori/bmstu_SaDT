#include "hash_func.h"

void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i = 0;

    do {
        s[i++] = n % 10 + '0';   
    } while ((n /= 10) > 0);     

    s[i] = '\0';
    reverse(s);
}

int read_filename(char *filename, int *max_size, int *cur_size)
{
    printf("Введите максимальный размер для структур(от 1 до 250): ");
    if (scanf("%d", max_size) != 1 || *max_size > 250 || *max_size < 1)
    {
        printf("\nНеверный размер хэш-таблицы.\n\n");
        return ERROR_SIZE;
    }

    printf("Введите размер текущей хэш-таблицы и дерева(от 1 до 250): ");

    if (scanf("%d", cur_size) != 1 || *cur_size > *max_size || *cur_size < 1)
    {
        printf("\nНеверный размер хэш-таблицы.\n\n");
        return ERROR_SIZE;
    }

    char str_size[5];
    itoa(*cur_size, str_size);
    
    char py_sys[] = "python3 data.py ";
    char *temp = strcat(py_sys, str_size);

    system(temp);

    char name[] = "data_";
    temp = strcat(name, str_size);
    
    strcat(temp, ".txt");
    strcpy(filename, temp);

    return EXIT_SUCCESS;
}

// unsigned long hash_func(char *leaf, struct tree *tree, int *compare)
// {

//     int sum = 0;
//     for (int i = 0; i < (int)strlen(leaf); i++)
//     {
//         sum += leaf[i]^tree->rand[i];
//     }
//     int ind = sum % tree->hash_size;
//     struct hash_slot *buf = malloc(sizeof(struct hash_slot));
//     strcpy(buf->value, leaf);
//     if (tree->hash_table[ind] == NULL)
//     {
//         buf->next = NULL;
//         tree->hash_table[ind] = buf;
//     }
//     else
//     {
//         buf->next = tree->hash_table[ind];
//         tree->hash_table[ind] = buf;
//     }
//     (*compare)++;

//     return t;
// }


int create_hash(char *filename, hash_table_t **table)
{
    FILE *f;
    if (!(f = fopen(filename, "r")))
    {
        printf("\nОшибка. Невозможно открыть файл %s.\n", filename);
        return ERROR_FILE;
    }
    char str[255];
    int count = 0;
    
    while (fgets(str, 255, f))
    { 
        str[strlen(str) - 1] = '\0';
        char *name = strdup(str);
        (*table)->array[count].name = name;
        count++;
    }

    fclose(f);

    if (!count)
    {
        printf("\nОшибка.Файл %s пустой.\n", filename);
        return ERROR_EMPTY_FILE;
    }

    if (count != (*table)->cur_size)
        printf("ОШибка! %d %d", count, (*table)->cur_size);

    return EXIT_SUCCESS;
}

void print_hash(hash_table_t *table, int cur_size)
{
    for (int i = 0; i < cur_size; i++)
        printf("%s \n", table->array[i].name);
}