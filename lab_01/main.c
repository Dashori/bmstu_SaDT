#include "process.h"

int main(void)
{

    struct real_number num = { 0 };
    struct int_number num_int = { 0 };
    int result[60] = { 0 };


    int count;
    setbuf(stdout, NULL);

    rules();

    if(read_real_number(&num))
    {
        printf("Error in input real number.\n\
Please check the rules and try again");
        return ERROR_IN_INPUT;
    }
    delete_point(num.mantissa, num.point_place);
    if(read_int_number(&num_int))
    {
        printf("Error in input integer number.\n\
Please check the rules and try again.\n");
        return ERROR_IN_INPUT;
    }
    if (multiplication(num.mantissa, num_int.int_num, result))
        return EXIT_FAILURE;
    round_up(result);
    if(check_the_order(&num, result, &count))
    {
        printf("Error. Order is overflow\n");
        return ERROR_OVERFLOW_ORDER;
    }
    print_multi_number(result, count, num.sign_mantissa, num_int.sign_int);

    return EXIT_SUCCESS;
}
