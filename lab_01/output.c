#include "output.h"

void rules(void)
{
    printf("Rules for input:\n\
When you enter the real number, please:\n\
0.Enter elements of number without space\n\
1.Enter the sign of mantissa(+ or -)\n\
2.After the first point enter the mantissa(max 30 numbers,necessarily 1 point,\n\
you must enter the number before point)\n\
3.After the second point enter the symbol of exponenta - 'e'\n\
4.After the third point enter the sign of order(+ or -)\n\
5.After the fourth point enter the order(max 5 numbers)\n\
6.Click enter\n\n\
When you enter the integer number, please:\n\
0.Enter elements of number without space\n\
1.Enter the number(max 30 numbers) with sign of number(+ or -)\n\
2.Click enter\n\n");
}

char check_the_sign(char sign_1, char sign_2)
{
    if (sign_1 == sign_2)
        return '+';
    else
        return '-';
}

void print_multi_number(int *result, int count, char sign_1, char sign_2)
{
    size_t index = MAX_MULTI, end_2 = MAX_MULTI;
    size_t end = 1;
    size_t j = 0, i = 0;

    while(result[j] == 0)
        j++;

    if (j < 30)
    {
        while(result[j + 30 - end] == 0)
            end++;
        if (end == 1)
            end = j + 30;
        else
            end = j + 30 - end + 1;
    }
    else
    {
        while(result[end_2 - 1] == 0)
            end_2--;
        end = end_2;
    }

    if (j == index)
    {
        printf("\nResult: 0.0e0");
        return;
    }

    printf("\nResult: %c0.", check_the_sign(sign_1, sign_2));

    for (i = j; i < end; i++)
        printf("%d",result[i]);
    printf("e%i",count);

    return;
}
