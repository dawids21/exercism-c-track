#include "run_length_encoding.h"
#include <stdlib.h>
#include <string.h>

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