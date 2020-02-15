#include "atbash_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char CIPHER[] = "zyxwvutsrqponmlkjihgfedcba";

char *atbash_encode(const char *input)
{
    char* result = (char*) malloc(MAX_LEN);
    int length = 0;
    int char_num = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if(isalpha(input[i]))
        {
            /*  find index of letter in ALPHABET using ASCII postion
                and add letter at the same position in CIPHER to result*/
            result[length] = CIPHER[tolower(input[i]) - 'a'];
            length++;
            char_num++;
        }
        //  space every 5 letters
        if (char_num == 5)
        {
            result[length] = ' ';
            length++;
            char_num = 0;
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
    }
    result[length] = '\0';
    return result;
}