#include "diamond.h"
#include <stdio.h>
#include <stdlib.h>

char **make_diamond(const char letter)
{
    int length = (letter - 'A') * 2 + 1;
    char **diamond = (char **)calloc(length, sizeof(char *));
    for (int i = 0; i < length; i++)
    {
        diamond[i] = (char *)calloc(length + 1, sizeof(char));
    }

    sprintf(diamond[0], "%*c", (length + 1) / 2, letter);
    if (length > 1)
    {
        sprintf(diamond[length - 1], "%*c", (length + 1) / 2, letter);
    }
    return diamond;
}