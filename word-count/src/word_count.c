#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "word_count.h"
#define OUT_WORD 0
#define IN_WORD 1

int word_count(const char *input_text, word_count_word_t *words)
{
    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);
    char word[MAX_WORD_LENGTH];
    int analyze = 0;
    int state = OUT_WORD;
    int counter = 0;
    while (input_text[analyze])
    {
        do
        {
            state = OUT_WORD;
            for (int i = 0; ; i++, analyze++)
            {
                if (i == MAX_WORD_LENGTH+1)
                    return -1;
                if (isalnum(input_text[analyze]) || (input_text[analyze] == '\'' && isalnum(input_text[analyze+1]) && state == IN_WORD))
                {
                    if (state == OUT_WORD)
                        state = IN_WORD;
                    word[i] = tolower(input_text[analyze]);
                }
                else
                {
                    state = OUT_WORD;
                    word[i] = '\0';
                    break;
                }

            }
        } while(state == IN_WORD);
        if (word[0] != '\0')
        {
            for (int i = 0; i <= MAX_WORDS; i++)
            {
                if (strcmp(words[i].text, word) == 0)
                {
                    words[i].count++;
                    break;
                }
                else if (i == MAX_WORDS-1)
                {
                    strcpy(words[counter].text, word);
                    words[counter].count = 1;
                    counter++;
                    break;
                }
            }
            if (counter > MAX_WORDS)
                return -2;
        }
        if (input_text[analyze] != '\0')
            analyze++;
    }
    return counter;

}
