#include "diamond.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter)
{
    if (letter < 'A' || letter > 'Z')
    {
        return NULL;
    }

    int length = (letter - 'A') * 2 + 1;
    char **diamond = (char **)calloc(length, sizeof(char *));
    for (int i = 0; i < length; i++)
    {
        diamond[i] = (char *)calloc(length + 1, sizeof(char));
        memset(diamond[i], ' ', length);
    }

    for (int row = 0; row < (length + 1) / 2; row++)
    {
        diamond[row][(length - 1) / 2 - row] = 'A' + row;
        diamond[row][(length - 1) / 2 + row] = 'A' + row;
        diamond[length - 1 - row][(length - 1) / 2 - row] = 'A' + row;
        diamond[length - 1 - row][(length - 1) / 2 + row] = 'A' + row;
    }

    return diamond;
}