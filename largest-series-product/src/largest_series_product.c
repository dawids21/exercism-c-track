#include "largest_series_product.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

static bool has_only_digits(char *str);

int64_t largest_series_product(char *digits, size_t span)
{
    if (strlen(digits) < span || !has_only_digits(digits))
    {
        return -1;
    }
    if (span == 0)
    {
        return 1;
    }

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

static bool has_only_digits(char *str)
{
    bool only_digits = true;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            only_digits = false;
            break;
        }
    }
    return only_digits;
}