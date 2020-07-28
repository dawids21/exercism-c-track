#include "all_your_base.h"
#include <bits/stdint-intn.h>
#include <math.h>

static int64_t convert_number_to_base_10(int8_t* digits, int16_t input_base, size_t length);
static int64_t power(int8_t base, int8_t exponent);
static int8_t find_max_exponent(int64_t number, int16_t base);

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length)
{
    int64_t number = convert_number_to_base_10(digits, input_base, input_length);
    int8_t max_exponent = find_max_exponent(number, output_base);
    for (int i = max_exponent; i >= 0; i--) {
        digits[i - max_exponent] = number / power(output_base, i);
        number %= power(output_base, i);
    }
    return max_exponent;
}

static int64_t convert_number_to_base_10(int8_t* digits, int16_t input_base, size_t length)
{
    int64_t number = 0;
    int exponent = length - 1;
    for (size_t i = 0; i < length; i++) {
        number += digits[i] * power(input_base, exponent);
        exponent--;
    }
    return number;
}

static int64_t power(int8_t base, int8_t exponent)
{
    int64_t number = 1;
    for (int i = 1; i <= exponent; i++) {
        number *= base;
    }
    return number;
}

// find the biggest number that is smaller than given number and return its exponent
static int8_t find_max_exponent(int64_t number, int16_t base)
{
    int8_t max = 0;
    int16_t current_exponential = 1;
    for (int i = 1; i < DIGITS_ARRAY_SIZE; i++) {
        current_exponential *= base;
        if (number < current_exponential) {
            max = i - 1;
        } else {
            break;
        }
    }
    return max;
}
