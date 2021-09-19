#include "multiplication.h"

void delete_point(char *mantissa, size_t point_place)
{
    for(size_t i = point_place; i < strlen(mantissa) - 1; i++)
        mantissa[i] = mantissa[i + 1];
    mantissa[strlen(mantissa) - 1]= 0;
}

void multiplication(char *num1, char *num2, int *result)
{
    int temp = 0;
    size_t index = 59, j = 0, i = 0;

    for(i = 0; i < strlen(num2); i++)
    {
        temp = 0;

        for(j = 0; j < strlen(num1); j++)
        {
            int c = (num1[strlen(num1) - j - 1] - '0')*(num2[strlen(num2) - i - 1] - '0');
            c = c + temp;
            temp = c / 10;
            c = c % 10;
            result[index - (i + j)] += c;
        }

        if(temp)
            result[index - (i + j)] += temp;
    }

    for(int i = index; i >= 0 ; i--)
        if(result[i] >= 10)
        {
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
}

void round_up(int *result)
{
    size_t index = 59, j = 0;

    while(result[j] == 0)
        j++;

    if (index - j < 30)
        return;

    if (result[j + 30] < 5)
        return;

    result[j + 29]++;

    for(int i = j + 29; i >= 0 ; i--)
    {
        if(result[i] >= 10)
        {
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
        else
            return;
    }
}

int check_the_order(int order, int *result, int *count)
{
    size_t j = 0;

    while(result[j] == 0)
        j++;
    *count =  60 - j + order;

    if (abs(*count) > 99999)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}


