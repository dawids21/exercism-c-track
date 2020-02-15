#include "say.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *from_0_to_999(int number);
static int split_into_chunks(int64_t input, char **chunks);
static void free_buffers(char **buffers, size_t number);

static const char *one_to_nineteen[19] = {"one", "two", "three", "four", "five", "six", "seven",
                                          "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                                          "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                                          "nineteen"};
static const char *tens[8] = {"twenty", "thirty", "forty", 
                              "fifty", "sixty", "seventy", "eighty",
                              "ninety"};
static const char *hundreds[3] = {"thousand", "million", "billion"};

int say(int64_t input, char **ans)
{
    *ans = (char *)calloc(BUFFER, sizeof(char));
    if (input > 999999999999 || input < 0)
        return -1;
    if (input == 0)
        strcat(*ans, "zero");
    else
    {
        char *chunks[MAX_NUM_OF_CHUNKS];
        int number_of_chunks = split_into_chunks(input, chunks);
        if (number_of_chunks == 1)
            sprintf(*ans, "%s", chunks[0]);
        else
        {
            for (int i=number_of_chunks-1; i>=0; i--)
            {
                if (strcmp(chunks[i], ""))
                {
                    if (i != 0)
                        sprintf(*ans, "%s%s %s ", *ans, chunks[i], hundreds[i-1]);
                    else
                        sprintf(*ans, "%s%s ", *ans, chunks[i]);
                }
            }
            (*ans)[strlen(*ans)-1] = '\0';
        }
        free_buffers(chunks, number_of_chunks);
    }
    return 0;
}

static char *from_0_to_999(int number)
{
    char *chunk = (char *)calloc(CHUNK, sizeof(char));
    if (number >= 100)
    {
        if(number % 100 == 0)
            sprintf(chunk, "%s hundred", one_to_nineteen[(number/100)-1]);
        else
            sprintf(chunk, "%s hundred ", one_to_nineteen[(number/100)-1]);
        number %= 100;
    }
    if (number != 0)
    {
        if (number < 20)
            sprintf(chunk,"%s%s", chunk, one_to_nineteen[number-1]);
        else
        {
            sprintf(chunk,"%s%s", chunk, tens[(number/10)-2]);
            if (number % 10 != 0)
                sprintf(chunk, "%s-%s", chunk, one_to_nineteen[(number%10)-1]);
        }
    }
    return chunk;
}

static int split_into_chunks(int64_t input, char **chunks)
{
    int number_of_chunks = 0;
    while (input)
    {
        int tmp_chunk = input%1000;
        chunks[number_of_chunks] = from_0_to_999(tmp_chunk);
        number_of_chunks++;
        input /= 1000;
    }
    return number_of_chunks;
}

static void free_buffers(char **buffers, size_t number)
{
    for (size_t i=0; i<number; i++)
        free(buffers[i]);
}