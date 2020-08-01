#include "run_length_encoding.h"
#include <stdlib.h>
#include <string.h>

static size_t convert_number_to_char_array(int number, char *output);

char *encode(const char *text)
{
    char *encoded = (char *)calloc(MAX_STRING_LEN, sizeof(char));
    for (size_t i = 0; i < strlen(text) - 1; i++)
    {
    }

    return encoded;
}

char *decode(const char *data)
{
    char *decoded = NULL;
    (void)data;
    return decoded;
}

// returns length of the char array representation of the number
static size_t convert_number_to_char_array(int number, char *output)
{
    size_t length = (size_t)(log10(number)) + 1;
    char *current = &output[length - 1];
    do
    {
        *current-- = (number % 10) + '0';
        number /= 10;
    } while (number != 0);
    return length;
}