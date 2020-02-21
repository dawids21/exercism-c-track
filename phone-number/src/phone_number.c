#include "phone_number.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int extract_digits(const char* input, char* output);

char *phone_number_clean(const char *input)
{
    char* phone_number = (char*)malloc(sizeof(char)*BUFFER);
    int length = extract_digits(input, phone_number);
    if (length != 10)
    {
        strcpy(phone_number, "00000000000");
    }
    return phone_number;
}

static int extract_digits(const char* input, char* output)
{
    int length = 0;
    for (size_t i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]))
        {
            output[length] = input[i];
            length++;
        }
    }
    return length;
}