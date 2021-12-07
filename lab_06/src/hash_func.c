#include "hash_func.h"


int create_hash(void)
{
    int size;
    printf("Введите размер хэш-таблицы(от 1 до 2000): ");
    if (scanf("%d", &size) != 1 || size > 2000 || size < 1)
    {
        printf("\nНеверный размер хэш-таблицы.\n\n");
        return ERROR_SIZE;
    }

    return EXIT_SUCCESS;
}