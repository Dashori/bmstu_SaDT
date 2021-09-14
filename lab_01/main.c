#include "process.h"

int main(void)
{

    struct real_number num = { 0 };
    struct int_number num_int = { 0 };
    char result[59] = { 0 };

    setbuf(stdout, NULL);

    rules();

    if(read_real_number(&num))
    {
        printf("Error in input real number.\n\
Please check the rules and try again");
        return ERROR_IN_INPUT;
    }
    if(read_int_number(&num_int))
    {
        printf("Error in input integer number.\n\
Please check the rules and try again.\n");
        return ERROR_IN_INPUT;
    }
    char number_point[MAX_MANTISSA - 1];
    delete_point(num.mantissa, number_point, num.point_place);
    if (multiplication(number_point, num_int.int_num, result))
        return EXIT_FAILURE;
    print_multi_number(&num, &num_int, result);

    printf("OK");
    return EXIT_SUCCESS;
}
