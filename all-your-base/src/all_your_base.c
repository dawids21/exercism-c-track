#include "all_your_base.h"
#include <bits/stdint-intn.h>
#include <math.h>
#include <stdbool.h>

static bool has_incorrect_digits(int8_t *digits, int16_t base, size_t length);
static int64_t convert_number_to_base_10(int8_t *digits, int16_t input_base,
                                         size_t length);
static int64_t power(int8_t base, int8_t exponent);
static int8_t find_max_exponent(int64_t number, int16_t base);

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length)
{
    if (input_base <= 1 || output_base <= 1 || input_length <= 0 || has_incorrect_digits(digits, input_base, input_length))
    {
        digits[0] = 0;
        return 0;
    }
    int64_t number = convert_number_to_base_10(digits, input_base, input_length);
    if (number == 0)
    {
        digits[0] = 0;
        return 0;
    }

    int8_t max_exponent = find_max_exponent(number, output_base);
    for (int i = max_exponent; i >= 0; i--)
    {
        int next_exponential_to_multiply = power(output_base, i);
        digits[max_exponent - i] = number / next_exponential_to_multiply;
        number %= next_exponential_to_multiply;
    }
    return max_exponent + 1;
}

// incorrect digits are negative digits and these bigger or equal to base
static bool has_incorrect_digits(int8_t *digits, int16_t base, size_t length)
{
    bool incorrect_digits = false;
    for (size_t i = 0; i < length; i++)
    {
        if (digits[i] < 0 || digits[i] >= base)
        {
            incorrect_digits = true;
            break;
        }
    }
    return incorrect_digits;
}

static int64_t convert_number_to_base_10(int8_t *digits, int16_t input_base,
                                         size_t length)
{
    int64_t number = 0;
    int exponent = length - 1;
    for (size_t i = 0; i < length; i++)
    {
        if (digits[i] == 0)
        {
            // leading zeroes are forbidden
            if (number == 0)
            {
                break;
            }
            // other zeroes are irrelevent
            else
            {
                exponent--;
                continue;
            }
        }
        number += digits[i] * power(input_base, exponent);
        exponent--;
    }
    return number;
}

static int64_t power(int8_t base, int8_t exponent)
{
    int64_t number = 1;
    for (int i = 1; i <= exponent; i++)
    {
        number *= base;
    }
    return number;
}

// find the biggest number that is smaller than given number and return its
// exponent
static int8_t find_max_exponent(int64_t number, int16_t base)
{
    int8_t max = 0;
    int64_t current_exponential = 1;
    for (int i = 1; i < DIGITS_ARRAY_SIZE; i++)
    {
        current_exponential *= base;
        if (number >= current_exponential)
        {
            max = i;
        }
        else
        {
            break;
        }
    }
    return max;
}
