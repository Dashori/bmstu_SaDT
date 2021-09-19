#include "process.h"

void rules(void)
{
    printf("Rules for input:\n\
When you enter the real number, please:\n\
0.Enter elements of number without space\n\
1.Enter the sign of mantissa(+ or -)\n\
2.After the first point enter the mantissa(max 30 numbers and necessarily 1 point,\n\
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

int read_real_number(struct real_number *num)
{
    printf("Enter the real numbers according to the rules:");
    if(fgets(num->real_num, MAX_STR, stdin) == NULL)
        return ERROR_IN_INPUT;

    if(trim(num->real_num))
        return ERROR_IN_INPUT;

    if(input_mantissa(num))
        return ERROR_IN_INPUT;

    if(input_order(num))
        return ERROR_IN_INPUT;

    return EXIT_SUCCESS;

}

int input_mantissa(struct real_number *num)
{
    if(is_sign_correct(num->real_num[0]))
        return ERROR_IN_INPUT;

    num->sign_mantissa = num->real_num[0];
    num->point_place = 0;

    for(size_t i = 1; num->real_num[i] != 'e'; i++)
    {
        if (num->real_num[i] == '.')
            num->point_place = i - 1;
        else if (num->real_num[i] != '.' && !isdigit(num->real_num[i]))
            return ERROR_IN_INPUT;
        num->mantissa[i-1] = num->real_num[i];
    }
    if(!num->point_place)
        return ERROR_IN_INPUT;

    if(strlen(num->mantissa) >= MAX_MANTISSA)
        return ERROR_IN_INPUT;

    return EXIT_SUCCESS;
}

int input_order(struct real_number *num)
{
    if(num->real_num[strlen(num->mantissa) + 1] != 'e')
        return ERROR_IN_INPUT;

    if(is_sign_correct(num->real_num[strlen(num->mantissa) + 2]))
        return ERROR_IN_INPUT;
    num->sign_order = num->real_num[strlen(num->mantissa) + 2];

    char order_char[MAX_ORDER];
    size_t j = 0;

    for(size_t i = strlen(num->mantissa) + 3; i < strlen(num->real_num); i++)
    {
        if(!isdigit(num->real_num[i]))
            return ERROR_IN_INPUT;
        order_char[j++] = num->real_num[i];
    }

    if(strlen(order_char) > 5)
        return ERROR_IN_INPUT;
    num->order = atoi(order_char);

    if(num->sign_order == '-')
        num->order *= -1;

    num->order = num->order - strlen(num->mantissa) + 1 + num->point_place;

    return EXIT_SUCCESS;
}

int read_int_number(struct int_number *num)
{
    printf("Enter the integer number according the rules:");

    if(fgets(num->int_num, MAX_INT, stdin) == NULL)
        return ERROR_IN_INPUT;

    if(trim(num->int_num))
        return ERROR_IN_INPUT;

    if(is_sign_correct(num->int_num[0]))
        return ERROR_IN_INPUT;

    num->sign_int = num->int_num[0];

    for(size_t i = 1; i < strlen(num->int_num); i++)
    {
        if(!isdigit(num->int_num[i]))
            return ERROR_IN_INPUT;
        num->int_num[i-1] = num->int_num[i];
    }
    num->int_num[strlen(num->int_num) - 1] = 0;

    return EXIT_SUCCESS;
}

int trim(char *str)
{
    if(str[strlen(str) - 1] != '\n')
        return EXIT_FAILURE;
    str[strlen(str) - 1] = 0;
    return EXIT_SUCCESS;
}

int is_sign_correct(char sign)
{
    if (sign != '-' && sign != '+')
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int delete_point(char *mantissa, size_t point_place)
{
    for(size_t i = point_place; i < strlen(mantissa) - 1; i++)
        mantissa[i] = mantissa[i + 1];
    mantissa[strlen(mantissa) - 1 ]= 0;

    return EXIT_SUCCESS;
}

int multiplication(char *num1, char *num2, int *result)
{
    int temp = 0;
    size_t index= 59;
    size_t j = 0;
    size_t i = 0;

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

    return EXIT_SUCCESS;
}

void round_up(int *result)
{

    size_t index = 59;
    size_t j = 0;

    while(result[j] == 0)
        j++;

    if (index - j < 30)
        return;
    printf(" %d ", result[j+30]);

    if (result[j + 30] < 5)
        return;

    result[j + 29]++;
    printf("ROUND ");

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

char check_the_sign(char sign_1, char sign_2)
{
    if (sign_1 == sign_2)
        return '+';
    else
        return '-';
}

int check_the_order(struct real_number *num, int *result, int *count)
{
    size_t j = 0;
    while(result[j] == 0)
        j++;
    *count =  60 - j + num->order;
    if (abs(*count) > 99999)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int print_multi_number(int *result, int count, char sign_1, char sign_2)
{
    size_t index = 60;
    size_t end = 1;
    size_t end_2 = 60;
    size_t j = 0;
    size_t i = 0;
//    printf("\n");
//    for(size_t i = 0; i < 60; i++)
//        printf("%d", result[i]);
//    printf("\n");

    while(result[j] == 0)
        j++;
//    printf(" %zu ", j);
    if (j < 30)
    {
        while(result[j + 30 - end] == 0)
            end++;
//        printf(" %zu ", end);
        if (end == 1)
            end = j + 30;
        else
        {
            size_t temp = j + 30 - end + 1;
            end = temp;
        }
//            end += 30 + j;

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
        return EXIT_SUCCESS;
    }

    printf("\nResult: %c0.", check_the_sign(sign_1, sign_2));

    for (i = j; i < end; i++)
        printf("%d",result[i]);
    printf("e");
    printf("%i", count);
    return EXIT_SUCCESS;
}
