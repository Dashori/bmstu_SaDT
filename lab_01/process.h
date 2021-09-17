#ifndef _PROCESS_H_
#define _PROCESS_H_ 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 41
#define MAX_MANTISSA 32
#define MAX_ORDER 7
#define MAX_INT 33

#define ERROR_IN_INPUT 1
#define ERROR_OVERFLOW_ORDER 2

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

void rules(void);
int read_real_number(struct real_number *num);
int input_mantissa(struct real_number *num);
void normalisation(struct real_number *num);
int input_order(struct real_number *num);
int read_int_number(struct int_number *num);

int is_sign_correct(char sign);
int trim(char *str);
int delete_point(char *mantissa, size_t point_place);
int multiplication(char *num1, char *num2, int *result);
void round_up(int *result);
char check_the_sign(char sign_1, char sign_2);
int check_the_order(struct real_number *num, int *result, int *count);
int print_multi_number(int *result, int count, char sign_1, char sign_2);

#endif
