#include "binary.h"
#include "string.h"
#include "math.h"

int convert(const char *input)
{
    int number = 0;
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        char digit = input[i];
        if (digit != '1' && digit != '0')
        {
            return INVALID;
        }
        if (digit == '1')
        {
            number += (int)pow(2, strlen(input) - 1 - i);
        }
    }
    return number;
}