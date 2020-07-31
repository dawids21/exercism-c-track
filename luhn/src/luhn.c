#include "luhn.h"
#include <string.h>

static bool has_invalid_chars(const char *str);
static int count_digits(const char *str);

bool luhn(const char *num)
{
    if (has_invalid_chars(num) || count_digits(num) <= 1)
    {
        return false;
    }
}

static bool has_invalid_chars(const char *str)
{
    bool invalid_chars = false;
    return invalid_chars;
}

static int count_digits(const char *str)
{
    int num_of_digits = 0;
    return num_of_digits;
}