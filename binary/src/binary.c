#include "binary.h"
#include "string.h"
#include "math.h"

static int power(const int base, const int exponent);

int convert(const char *input)
{
    int number = 0;
    int input_len = strlen(input);
    for (int i = input_len - 1; i >= 0; i--)
    {
        char digit = input[i];
        if (digit != '1' && digit != '0')
        {
            return INVALID;
        }
        if (digit == '1')
        {
            /**
             * Number:      1010
             * strlen-1:    3333
             * i:           0123
             * exponent:    3210
             * So to get exponent function subtract i from strlen-1
             **/
            number += power(2, input_len - 1 - i);
        }
    }
    return number;
}

static int power(const int base, const int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}