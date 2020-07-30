#include "palindrome_products.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_palindrome(int number);
static size_t convert_number_to_char_array(int number, char *output);

typedef struct
{
    int number;
    factor_t factors;
} palindrome_t;

static bool is_palindrome(int number)
{
    bool palindrome = true;
    char *digits;
    size_t length = convert_number_to_char_array(number, digits);
    char *begin = digits;
    char *end = digits + length - 1;
    while (begin < end)
    {
        if (*begin == *end)
        {
            begin++;
            end--;
        }
        else
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

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