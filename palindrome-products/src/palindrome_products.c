#include "palindrome_products.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_palindrome(int number);
static size_t convert_number_to_char_array(int number, char *output);
static int is_palindrome_in_array(palindrome_t *array,
                                  int palindrome,
                                  size_t array_length);                  //TODO
static void add_factors(palindrome_t palindrome, int first, int second); //TODO
static size_t add_palindrome(palindrome_t *array,
                             int first_factor,
                             int second_factor,
                             size_t array_length);

typedef struct
{
    int number;
    factor_t *factors;
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

// returns length of the char array representation of the number
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

static void add_factors(palindrome_t palindrome, int first, int second) //TODO
{
    factor_t *factors = (factor_t *)calloc(1, sizeof(factor_t));
    factors->factor_a = first;
    factors->factor_b = second;
}

static size_t add_palindrome(palindrome_t *array,
                             int first_factor,
                             int second_factor,
                             size_t array_length)
{
    palindrome_t palindrome;
    palindrome.number = first_factor * second_factor;
    palindrome.factors = (factor_t *)calloc(1, sizeof(factor_t));
    palindrome.factors->factor_a = first_factor;
    palindrome.factors->factor_b = second_factor;
    palindrome.factors->next = NULL;
    array[array_length] = palindrome;
    return array_length + 1;
}