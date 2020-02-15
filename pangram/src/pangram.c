#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "pangram.h"

bool is_pangram(const char* sentence)
{
    if (sentence == NULL)
        return false;

    bool alphabet[SIZE];

    for (int i = 0; i < SIZE; i++)
        alphabet[i] = false;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (isalpha(sentence[i]) && !alphabet[tolower(sentence[i]) - 'a'])
            alphabet[tolower(sentence[i]) - 'a'] = true;
    }

    for(int i = 0; i < SIZE; i++)
    {
        if (!alphabet[i])
            return false;
    }
    return true;
}

