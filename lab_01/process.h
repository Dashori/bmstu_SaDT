#ifndef _PROCESS_H_
#define _PROCESS_H_ 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 41
#define MAX_MANTISSA 32
#define MAX_ORDER 7
#define MAX_INT 31
#define E_AND_SIGN 3
#define SIGN 2

#define  ERROR_IN_INPUT 1

struct real_number
{
    char real_num[MAX_STR];
    char sign_mantissa[SIGN];
    char mantissa[MAX_MANTISSA];
    char e_and_sign_order[E_AND_SIGN];
    int order;
    size_t point_place;

};
struct int_number
{
    char sign_int[SIGN];
    char int_num[MAX_INT];
};
//char signs[] = "+- ";

//int read_sign(char sign[SIGN]);
//int read_order(char real_order[MAX_ORDER_REAL]);
void rules(void);
int read_real_number(struct real_number *num);
int input_mantissa(struct real_number *num);
int input_order(struct real_number *num);
int read_int_number(struct int_number *num);
int is_sign_correct(char sign);
int trim(char *str);
int delete_point(char *mantissa, char *number, size_t point_place);
int multiplication(char *num1, char *num2, char *result);
int print_multi_number(struct real_number *num1, struct int_number *num2, char *result);

#endif
