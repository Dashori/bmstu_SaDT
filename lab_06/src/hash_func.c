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

int read_filename(char *filename)
{
    int size;
    
    printf("Введите размер хэш-таблицы и дерева(от 1 до 250): ");

    if (scanf("%d", &size) != 1 || size > 250 || size < 1)
    {
        printf("\nНеверный размер хэш-таблицы.\n\n");
        return ERROR_SIZE;
    }

    char str_size[5];
    itoa(size, str_size);
    
    char py_sys[] = "python3 data.py ";
    char *temp = strcat(py_sys, str_size);

    system(temp);

    char name[] = "data_";
    temp = strcat(name, str_size);
    
    strcat(temp, ".txt");
    strcpy(filename, temp);

    return EXIT_SUCCESS;
}