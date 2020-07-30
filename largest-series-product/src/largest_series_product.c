#include "largest_series_product.h"

int64_t largest_series_product(char *digits, size_t span)
{
    int64_t max = 0;
    for (size_t i = 0; digits[i + span - 1] != '\0'; i++)
    {
        int64_t candidate = digits[i] - '0';
        for (size_t digits_index = 1; digits_index < span; digits_index++)
        {
            candidate *= digits[digits_index + i] - '0';
        }
        max = candidate > max ? candidate : max;
    }
    return max;
}