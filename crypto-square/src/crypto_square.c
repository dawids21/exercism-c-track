#include "crypto_square.h"
#include <ctype.h>
#include <string.h>

static size_t normalize_string(const char *input, char *output);

static size_t normalize_string(const char *input, char *output)
{
    size_t output_len;
    for (size_t i = 0; i < strlen(input); i++)
    {
        char ch = input[i];
        if (isalpha(ch))
        {
            output[output_len++] = tolower(ch);
        }
        else if (isdigit(ch))
        {
            output[output_len++] = ch;
        }
    }
    return output_len;
}