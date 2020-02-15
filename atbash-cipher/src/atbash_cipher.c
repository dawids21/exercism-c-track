#include "atbash_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char CIPHER[] = "zyxwvutsrqponmlkjihgfedcba";

char *atbash_encode(const char *input)
{
    char* result = (char*)malloc(MAX_LEN);
    int length = 0;
    int char_num_space = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]))
        {
            //  space every 5 letters but only if there are more letters
            if (char_num_space == 5)
            {
                result[length] = ' ';
                length++;
                char_num_space = 0;
            }
            if(isalpha(input[i]))
            {
                /*  find index of letter in ALPHABET and add letter at
                    the same position in CIPHER to result*/
                result[length] = CIPHER[strchr(ALPHABET, tolower(input[i]))-ALPHABET];
                length++;
                char_num_space++;
            }
            else if (isdigit(input[i]))
            {
                result[length] = input[i];
                length++;
                char_num_space++;
            }
        }
    }
    result[length] = '\0';
    return result;
}

char *atbash_decode(const char *input)
{
    char* result = (char*) malloc(MAX_LEN);
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if(isalpha(input[i]))
        {
            /*  find index of letter in CIPHER and add letter at the same position
                in ALPHABET to result*/
            result[length] = ALPHABET[strchr(CIPHER, tolower(input[i]))-CIPHER];
            length++;
        }
        else if (isdigit(input[i]))
        {
            result[length] = input[i];
            length++;
        }
    }
    result[length] = '\0';
    return result;
}