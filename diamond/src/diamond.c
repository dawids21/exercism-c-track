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

    sprintf(diamond[0], "%*c%*c", (length + 1) / 2,
            'A', (length + 1) / 2, '\0');

    char current_letter = 'B';
    for (int row = 1; row < length - 1; row++)
    {
        sprintf(diamond[row], "%*c%*c%*c",
                (length + 1) / 2 - (current_letter - 'A'),
                current_letter,
                2 * (current_letter - 'A'),
                current_letter,
                (length + 1) / 2 - (current_letter - 'A'),
                '\0');
        if (row < (length - 1) / 2)
        {
            current_letter--;
        }
        else
        {
            current_letter++;
        }
    }

    if (length > 1)
    {
        sprintf(diamond[length - 1], "%*c%*c", (length + 1) / 2,
                'A', (length + 1) / 2, '\0');
    }
    return diamond;
}