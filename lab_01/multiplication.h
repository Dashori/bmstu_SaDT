#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MULTI 60
#define MAX_ORDER 99999

#define ERROR_OVERFLOW_ORDER 2

void delete_point(char *mantissa, size_t point_place);
void multiplication(char *num1, char *num2, int *result);
int round_up(int *result);
int check_the_order(int order, int *result, int *count);

#endif
