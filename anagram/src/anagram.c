#include "anagram.h"
#include <string.h>
#include <ctype.h>

static int check(char* tab);
static void lower_case(const char* word, char* dest);

void anagrams_for(const char* word, struct candidates* candidates)
{
    char copied_word[strlen(word)];
    char candidate[MAX_STR_LEN];
    char* char_pointer;

    for (unsigned int i=0; i < candidates->count; i++)
    {
        strcpy(copied_word, word);
        lower_case(copied_word, copied_word);
        lower_case(candidates->candidate[i].candidate, candidate);
        if (!strcmp(copied_word, candidate))
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        else
        {
            for (int j=0; candidate[j] != '\0'; j++)
            {
                if ((char_pointer = strchr(copied_word, candidate[j])))
                {
                    *char_pointer = USED_SYMBOL;
                    candidate[j] = USED_SYMBOL;
                }
                else
                    break;
            }
        }
        if (check(copied_word) && check(candidate))
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        else
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
    }
}

static int check(char* tab)
{
    for (int i=0; tab[i] != '\0'; i++)
        if (tab[i] != USED_SYMBOL)
            return 0;
    return 1;
}

static void lower_case(const char* word, char* dest)
{
    int i;
    for (i=0; word[i] != '\0'; i++)
        dest[i] = tolower(word[i]);
    dest[i] = '\0';
}








