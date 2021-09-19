#ifndef _READ_NUMBERS_H
#define _READ_NUMBERS_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 41
#define MAX_MANTISSA 32
#define MAX_ORDER 7
#define MAX_INT 33

#define ERROR_IN_INPUT 1

struct real_number
{
    char real_num[MAX_STR];
    char sign_mantissa;
    char mantissa[MAX_MANTISSA];
    char sign_order;
    int order;
    size_t point_place;

};
struct int_number
{
    char sign_int;
    char int_num[MAX_INT];
};


int read_real_number(struct real_number *num);
int input_mantissa(struct real_number *num);
void normalisation(struct real_number *num);
int input_order(struct real_number *num);
int read_int_number(struct int_number *num);
int is_sign_correct(char sign);
int trim(char *str);

#endif
