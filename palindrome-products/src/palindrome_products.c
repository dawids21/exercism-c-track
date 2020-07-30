#include "palindrome_products.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

static size_t convert_number_to_char_array(int number, char *output);

static size_t convert_number_to_char_array(int number, char *output)
{
    size_t length = (size_t)(log10(number)) + 1;
    output = (char)calloc(length, sizeof(char));
    char *current = output;
    do
    {
        *current++ = number % 10;
        number /= 10;
    } while (number != 0);
    return length;
}