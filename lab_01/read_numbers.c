#include "read_numbers.h"

int read_real_number(struct real_number *num)
{
    printf("                      +...............................e+.....\n");
    printf("Enter the real number:");

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
    printf("\n                         +..............................\n");
    printf("Enter the integer number:");

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
