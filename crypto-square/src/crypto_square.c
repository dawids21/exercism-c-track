#include "crypto_square.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static size_t normalize_string(const char *input, char *output);

char *ciphertext(const char *input)
{
    size_t input_len = strlen(input);
    if (input_len == 0)
    {
        return (char *)calloc(1, sizeof(char));
    }

    char normalized_string[input_len + 1];
    size_t normalized_len = normalize_string(input, normalized_string);

    int columns = (int)ceil(sqrt(normalized_len));
    int rows = (int)ceil((double)normalized_len / (double)columns);

    char *output = (char *)calloc(columns * rows + 1, sizeof(char));
    int output_index = 0;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (j * columns + i >= (int)normalized_len)
            {
                output[output_index++] = ' ';
            }
            else
            {
                output[output_index++] = normalized_string[j * columns + i];
            }
        }
        output[output_index++] = (i == columns - 1) ? '\0' : ' ';
    }

    return output;
}

static size_t normalize_string(const char *input, char *output)
{
    size_t output_len = 0;
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
    output[output_len] = '\0';
    return output_len;
}