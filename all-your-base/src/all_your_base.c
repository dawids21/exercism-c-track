#include "all_your_base.h"
#include <bits/stdint-intn.h>
#include <math.h>

static int64_t convert_number_to_base_10(int8_t *digits, int16_t input_base,
                                         size_t length);
static int64_t power(int8_t base, int8_t exponent);
static int8_t find_max_exponent(int64_t number, int16_t base);

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length)
{
    if (input_base <= 0 || output_base <= 0 || input_length <= 0)
    {
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
        digits[max_exponent - i] = number / power(output_base, i);
        number %= power(output_base, i);
    }
    return max_exponent + 1;
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
            if (number == 0)
            {
                break;
            }
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
