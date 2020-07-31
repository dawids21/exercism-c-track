#include "crypto_square.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static size_t normalize_string(const char *input, char *output);

char *ciphertext(const char *input)
{
    char *output = (char *)calloc(strlen(input), sizeof(char));
    size_t normalized_len = normalize_string(input, output);
    return output;
}

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