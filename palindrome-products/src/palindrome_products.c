#include "palindrome_products.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10

typedef struct
{
    int number;
    factor_t *factors;
} palindrome_t;

static bool is_palindrome(int number);
static size_t convert_number_to_char_array(int number, char *output);
static void add_factors(factor_t **factors, int first, int second);
static void free_factor(factor_t **factor);
static void print_invalid_input_error(int from, int to, char *output);
static void print_no_palindrome_error(int from, int to, char *output);

product_t *get_palindrome_product(int from, int to)
{
    product_t *palindrome_product = (product_t *)calloc(1, sizeof(product_t));
    if (from > to)
    {
        print_invalid_input_error(from, to, palindrome_product->error);
        return palindrome_product;
    }
    for (int first_factor = from; first_factor <= to; first_factor++)
    {
        for (int second_factor = first_factor; second_factor <= to; second_factor++)
        {
            int possible_number = first_factor * second_factor;
            if (possible_number == palindrome_product->largest)
            {
                add_factors(&palindrome_product->factors_lg, first_factor, second_factor);
            }
            else if (possible_number == palindrome_product->smallest)
            {
                add_factors(&palindrome_product->factors_sm, first_factor, second_factor);
            }
            else if (is_palindrome(possible_number))
            {
                if (palindrome_product->smallest == 0 && palindrome_product->largest == 0)
                {
                    palindrome_product->smallest = possible_number;
                    add_factors(&palindrome_product->factors_sm, first_factor, second_factor);
                    palindrome_product->largest = possible_number;
                    add_factors(&palindrome_product->factors_lg, first_factor, second_factor);
                }
                else if (possible_number > palindrome_product->largest)
                {
                    free_factor(&palindrome_product->factors_lg);
                    palindrome_product->largest = possible_number;
                    add_factors(&palindrome_product->factors_lg, first_factor, second_factor);
                }
                else if (possible_number < palindrome_product->smallest)
                {
                    free_factor(&palindrome_product->factors_sm);
                    palindrome_product->smallest = possible_number;
                    add_factors(&palindrome_product->factors_sm, first_factor, second_factor);
                }
            }
        }
    }
    if (palindrome_product->smallest == 0 && palindrome_product->largest == 0)
    {
        print_no_palindrome_error(from, to, palindrome_product->error);
    }
    return palindrome_product;
}

void free_product(product_t *product)
{
    if (product == NULL)
    {
        return;
    }

    free_factor(&product->factors_lg);
    free_factor(&product->factors_sm);
    free(product);
    product = NULL;
}

static bool is_palindrome(int number)
{
    int reversed = 0;
    int temp = number;
    while (temp != 0)
    {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return number == reversed;
}

// returns length of the char array representation of the number
static size_t convert_number_to_char_array(int number, char *output)
{
    size_t length = (size_t)(log10(number)) + 1;
    char *current = &output[length - 1];
    do
    {
        *current-- = (number % 10) + '0';
        number /= 10;
    } while (number != 0);
    return length;
}

static void add_factors(factor_t **factors, int first, int second)
{
    factor_t *new_factors = (factor_t *)calloc(1, sizeof(factor_t));
    new_factors->factor_a = first;
    new_factors->factor_b = second;
    new_factors->next = NULL;
    if (*factors == NULL)
    {
        *factors = new_factors;
    }
    else
    {
        factor_t *current_factors = *factors;
        while (current_factors->next != NULL)
        {
            current_factors++;
        }
        current_factors->next = new_factors;
    }
}

static void free_factor(factor_t **factor)
{
    if (*factor == NULL)
    {
        return;
    }
    factor_t *current = *factor;
    factor_t *next = current->next;
    while (next != NULL)
    {
        free(current);
        current = NULL;
        current = next;
        next = current->next;
    }
    free(current);
    *factor = NULL;
}

static void print_invalid_input_error(int from, int to, char *output)
{
    strcpy(output, "invalid input: min is ");
    char number[MAX_DIGITS];
    size_t length = convert_number_to_char_array(from, number);
    strncat(output, number, length);
    strcat(output, " and max is ");
    length = convert_number_to_char_array(to, number);
    strncat(output, number, length);
}

static void print_no_palindrome_error(int from, int to, char *output)
{
    strcpy(output, "no palindrome with factors in the range ");
    char number[MAX_DIGITS];
    size_t length = convert_number_to_char_array(from, number);
    strncat(output, number, length);
    strcat(output, " to ");
    length = convert_number_to_char_array(to, number);
    strncat(output, number, length);
}