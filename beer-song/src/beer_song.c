#include "beer_song.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void verse(char *dst, const int number)
{
    if (dst == NULL)
    {
        printf("Invalid pointer");
        exit(EXIT_FAILURE);
    }
    strcpy(dst, "");

    switch (number)
    {
    case 0:
        strcpy(dst, "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n");
        break;
    case 1:
        strcpy(dst, "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n");
        break;
    default:
        sprintf(dst, "%d %s %d %s %d", number, "bottles of beer on the wall,", number, "bottles of beer.\nTake one down and pass it around,", number-1);
        if (number == 2) strcat(dst, " bottle of beer on the wall.\n");
        else strcat(dst, " bottles of beer on the wall.\n");
        break;
    }

}

void sing(char *dst, const int start, const int stop)
{
    if (dst == NULL)
    {
        printf("Invalid pointer");
        exit(EXIT_FAILURE);
    }
    char buffer[SIZE] = {0};
    strcpy(dst, "");

    for (int i = start; i >= stop; i--)
    {
        verse(buffer, i);
        strcat(dst, buffer);
        if (i != stop) strcat(dst, "\n"); //don't add new line after last line
    }
}
