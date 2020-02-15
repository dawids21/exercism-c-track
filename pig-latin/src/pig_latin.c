#include "pig_latin.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void move_consonant(char*, int);

char* translate (const char* phrase)
{
    int len;
    char sentence[strlen(phrase) + 1];
    strcpy(sentence, phrase);
    char* pig = (char*) calloc(30, sizeof(char));
    char* word = strtok(sentence, " ");
    bool vowel, moved;
    while (word != NULL)
    {
        len = strlen(word);
        vowel = false;
        moved = false;
        while (!vowel)
        {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || (moved && word[0] == 'y'))
            {
                strcat(pig, word);
                strcat(pig, "ay ");
                vowel = true;
            }
            else if ((word[0] == 'x' && word[1] == 'r') || (word[0] == 'y' && word[1] == 't'))
            {
                strcat(pig, word);
                strcat(pig, "ay ");
                vowel = true;
            }
            else if (word[0] == 'q' && word[1] == 'u')
            {
                move_consonant(word, len);
                move_consonant(word, len);
                strcat(pig, word);
                strcat(pig, "ay ");
                vowel = true;
            }
            else if (len == 2 && word[1] == 'y')
            {
                move_consonant(word, len);
                strcat(pig, word);
                strcat(pig, "ay ");
                vowel = true;
            }
            else
            {
                move_consonant(word, len);
                moved = true;
            }
        }
        word = strtok(NULL, " ");
    }
    pig[strlen(pig)-1] = '\0';
    return pig;
}

static void move_consonant(char* word, int len)
{
    char tmp[len+1];
    strcpy(tmp, word + 1);
    tmp[len-1] = word[0];
    tmp[len] = '\0';
    strcpy(word, tmp);
}
