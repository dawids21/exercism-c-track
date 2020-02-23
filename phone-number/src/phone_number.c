#include "phone_number.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int extract_digits(const char* input, char* output);

char *phone_number_clean(const char *input)
{
    char* phone_number = (char*)malloc(sizeof(char) * (strlen(input)+1));
    int length = extract_digits(input, phone_number);

    //Number is valid if has 11 digits and first digit is 1
    if (length == 11 && phone_number[0] == '1')
    {
        memmove(phone_number, &phone_number[1], 11);
        length--;
    }

    //Number has 10 digits and area and exchange code can't be 0 or 1
    if (length != 10 || phone_number[0] == '0' || phone_number[0] == '1' ||
        phone_number[3] == '0' || phone_number[3] == '1')
    {
        strcpy(phone_number, "0000000000");
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
        //Number can't contain letters
        else if (isalpha(input[i]))
        {
            length = 0;
            break;
        }
    }
    return length;
}