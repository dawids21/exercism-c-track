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

    bool should_double = false;
    int sum = 0;

    for (int i = (int)strlen(num) - 1; i >= 0; i--)
    {
        if (num[i] != ' ')
        {
            int number = num[i] - '0';
            sum += number;
            if (should_double)
            {
                sum += number;
                sum -= (number * 2 > 9) ? 9 : 0;
            }
            should_double = !should_double;
        }
    }
    return sum % 10 == 0;
}

static bool has_invalid_chars(const char *str)
{
    bool invalid_chars = false;
    char const *current_char = str;
    do
    {
        if (!isdigit(*current_char) && *current_char != ' ')
        {
            invalid_chars = true;
            break;
        }
    } while (*(++current_char) != '\0');

    return invalid_chars;
}

static int count_digits(const char *str)
{
    int num_of_digits = 0;
    char const *current_char = str;
    do
    {
        if (isdigit(*current_char))
        {
            num_of_digits++;
        }
    } while (*(++current_char) != '\0');
    return num_of_digits;
}