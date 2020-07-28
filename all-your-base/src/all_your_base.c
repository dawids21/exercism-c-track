#include "all_your_base.h"
#include <math.h>

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length)
{
    (void)digits;
    (void)input_base;
    (void)output_base;
    (void)input_length;
    return 0;
}

int8_t find_max_exponent(int64_t number, int16_t base)
{
    int8_t max = 0;
    for (int i = 1; i < DIGITS_ARRAY_SIZE; i++) {
        if (number < pow(base, i)) {
            max = i;
        } else {
            break;
        }
    }
    return max;
}
