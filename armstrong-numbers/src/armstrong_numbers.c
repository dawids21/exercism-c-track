#include "armstrong_numbers.h"
#include <stdio.h>
#include <string.h>

static int power(int base, int exponent);

int isArmstrongNumber(const int number)
{
    int result = 0;
    char string_number[BUFFER_SIZE];
    sprintf(string_number, "%d", number);
    int length = strlen(string_number);
    for (int i=0; i < length; i++) result += power(string_number[i] - '0', length);
    return (result == number);
}

static int power(int base, int exponent)
{
    if (base == 0) return 0;
    int result = 1;
    for (int i = 0; i < exponent; i++) result *= base;
    return result;
}
