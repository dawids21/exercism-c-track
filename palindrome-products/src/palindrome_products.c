#include "palindrome_products.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_PALINDROMES 20

static bool is_palindrome(int number);
static size_t convert_number_to_char_array(int number, char *output);
static int is_palindrome_in_array(palindrome_t *array,
                                  int palindrome,
                                  size_t array_length); //TODO
static void add_factors(palindrome_t palindrome, int first, int second);
static size_t add_palindrome(palindrome_t *array,
                             int first_factor,
                             int second_factor,
                             size_t array_length);
static palindrome_t find_max_palindrome(palindrome_t *array, size_t length);
static palindrome_t find_min_palindrome(palindrome_t *array, size_t length);

typedef struct
{
    int number;
    factor_t *factors;
} palindrome_t;

product_t *get_palindrome_product(int from, int to)
{
    product_t *palindrome_product = (product_t *)calloc(1, sizeof(product_t));
    palindrome_t palidromes[MAX_PALINDROMES]; // all possible palindromes
    size_t palindromes_array_length = 0;
    for (int first_factor = from; first_factor <= to; first_factor++)
    {
        for (int second_factor = first_factor; second_factor <= to; second_factor++)
        {
            if (is_palindrome(first_factor * second_factor))
            {
                int index = is_palindrome_in_array(palidromes,
                                                   first_factor * second_factor,
                                                   palindromes_array_length);
                if (index >= 0) // palindrome was found
                {
                    add_factors(palidromes[index], first_factor, second_factor);
                }
                else
                {
                    palindromes_array_length = add_palindrome(palidromes,
                                                              first_factor,
                                                              second_factor,
                                                              palindromes_array_length);
                }
            }
        }
    }

    palindrome_t max = find_max_palindrome(palidromes, palindromes_array_length);
    palindrome_t min = find_min_palindrome(palidromes, palindromes_array_length);
    palindrome_product->smallest = min.number;
    palindrome_product->largest = max.number;
    palindrome_product->factors_sm = min.factors;
    palindrome_product->factors_lg = max.factors;
    return palindrome_product;
}

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

static void add_factors(palindrome_t palindrome, int first, int second)
{
    factor_t *factors = (factor_t *)calloc(1, sizeof(factor_t));
    factors->factor_a = first;
    factors->factor_b = second;
    factors->next = NULL;
    factor_t *current_factors = palindrome.factors;
    while (current_factors->next != NULL)
    {
        current_factors++;
    }
    current_factors->next = factors;
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

static palindrome_t find_max_palindrome(palindrome_t *array, size_t length)
{
    palindrome_t max;
    for (size_t i = 0; i < length; i++)
    {
        max = array[i].number > max.number ? array[i] : max;
    }
    return max;
}

static palindrome_t find_min_palindrome(palindrome_t *array, size_t length)
{
    palindrome_t min;
    for (size_t i = 0; i < length; i++)
    {
        min = array[i].number < min.number ? array[i] : min;
    }
    return min;
}