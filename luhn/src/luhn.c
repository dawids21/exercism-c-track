#include "luhn.h"
#include <ctype.h>
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
    char current_char = *str;
    do
    {
        if (isdigit(current_char))
        {
            num_of_digits++;
        }
    } while (++current_char != '\0');
}