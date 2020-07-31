#include "luhn.h"
#include <string.h>

static has_invalid_chars(const char *str);

bool luhn(const char *num)
{
    if (has_invalid_chars(num) || strlen(num) <= 1)
    {
        return false;
    }
}