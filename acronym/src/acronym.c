#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 20


char *abbreviate(const char *phrase)
{
    if (phrase == NULL || *phrase == '\0')
        return NULL;
    char *abbreviation;
    abbreviation = malloc(sizeof(char) * SIZE);
    bool in_word = false;
    int j = 0;
    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (phrase[i] == ' ' || phrase[i] == '-')
        {
            if (in_word)
                in_word = false;
            else
                continue;
        }
        else if (isalpha(phrase[i]))
        {
            if (!in_word)
            {
                in_word = true;
                abbreviation[j] = toupper(phrase[i]);
                j++;
            }
            else
                continue;
        }
    }
    abbreviation[j] = '\0';
    return abbreviation;
}
