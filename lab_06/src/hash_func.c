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
    printf("Введите максимальный размер для структур(от 2 до 250): ");
    if (scanf("%d", max_size) != 1 || *max_size > 250 || *max_size < 2)
    {
        printf("\nНеверный размер.\n\n");
        return ERROR_SIZE;
    }

    printf("Введите размер текущей хэш-таблицы и дерева(от 2 до 250): ");

    if (scanf("%d", cur_size) != 1 || *cur_size > *max_size || *cur_size < 2)
    {
        printf("\nНеверный размер.\n\n");
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

node_table_t *create_node_table(char *name)
{
    node_table_t *temp = calloc(1, sizeof(node_table_t));
    
    if (!temp)
        return NULL;
    
    temp->name = name;
    temp->next = NULL;
    
    return temp;
}

node_table_t *list_add_end(node_table_t *node, node_table_t *list, int *compare)
{
    if (!list)
        return node;

    node_table_t *temp = list;

    for ( ; temp->next != NULL; temp = temp->next, (*compare)++);

    temp->next = node;

    return list;
}

int hash_func(char *name, int max_size)
{
    int sum = 0;

    for (int i = 0; i < (int)strlen(name); i++)
        sum += name[i]^(rand() % max_size);
    
    return sum % max_size;
}

void insert_hash_node(char *name, hash_table_t *table, int *compare)
{
    int res = hash_func(name, table->max_size);
    // printf("res = %d\n", res);

    if (table->array[res].name == NULL)
        table->array[res].name = name;
    else
    {
        (*compare)++;
        node_table_t *new_node = create_node_table(name);
        table->array[res].next = list_add_end(new_node, table->array[res].next, compare);
    }
}

int create_hash(char *filename, hash_table_t **table, int cur_size)
{
    FILE *f;
    if (!(f = fopen(filename, "r")))
    {
        printf("\nОшибка. Невозможно открыть файл %s.\n", filename);
        return ERROR_FILE;
    }
    char str[255];
    int count = 0;
    int compare = 0;

    while (fgets(str, 255, f))
    { 
        str[strlen(str) - 1] = '\0';
        char *name = strdup(str);

        insert_hash_node(name, *table, &compare);

        count++;
    }

    fclose(f);

    if (!count)
    {
        printf("\nОшибка.Файл %s пустой.\n", filename);
        return ERROR_EMPTY_FILE;
    }

    if (count != cur_size)
    {
        printf("Ошибка. Не все слова были записаны.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void print_list(node_table_t *head)
{
    while (head)
    {
        printf("%s ", head->name);
        head = head->next;
    }
}

void print_hash(hash_table_t table, int max_size)
{
    printf("\n");
    for (int i = 0; i < max_size; i++)
    {
        printf("%d: ", i);

        if (table.array[i].name != NULL)
            printf("%s ", table.array[i].name);
        if (table.array[i].next != NULL)
            print_list(table.array[i].next);
        printf("\n");
    }
    printf("\n");
}
