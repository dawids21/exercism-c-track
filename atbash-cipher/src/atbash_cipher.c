#include "atbash_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char CIPHER[] = "zyxwvutsrqponmlkjihgfedcba";

char *atbash_encode(const char *input)
{
    char* result = (char*) malloc(strlen(input)*sizeof(char)+1);
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if(isalpha(input[i]))
        {
            result[length] = CIPHER[tolower(input[i]) - 'a'];
            length++;
        }
    }
    result[length] = '\0';
    return result;
}

char *atbash_decode(const char *input)
{
    char* result = (char*) malloc(strlen(input)*sizeof(char)+1);
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if(isalpha(input[i]))
        {
            result[length] = ALPHABET[strchr(CIPHER, tolower(input[i]))-CIPHER];
            length++;
        }
    }
    result[length] = '\0';
    return result;
}