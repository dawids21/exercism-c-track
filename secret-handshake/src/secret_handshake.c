#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

const char** commands(int num)
{
    char **result;
    result = (char**) malloc(4 * sizeof(char*));
    for (int i = 0; i < 4; i++)
    {
        if (num == 0 || num == 16) *(result + i) = NULL;
        else *(result + i) = (char*) malloc(16 * sizeof(char));
    }
    if (num == 0 || num == 16) return (const char**) result;
    const char moves[4][17] = MOVES;
    int counter = 0;
    if (num & 0x10)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (num & (1<<i))
            {
                strcpy(result[counter],moves[i]);
                counter++;
            }
        }
    }
    else
    {
        for (int i = 0; i <= 3; i++)
        {
            if (num & (1<<i))
            {
                strcpy(result[counter],moves[i]);
                counter++;
            }
        }
    }
    return (const char**) result;
}
