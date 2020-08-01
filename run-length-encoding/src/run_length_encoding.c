#include "run_length_encoding.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static void encode_letter(char ch, int num_of_chars, char *output);
static void decode_letter(char ch, int num_of_chars, char *output);
static size_t convert_number_to_char_array(int number, char *output);
static int read_number(char const **p);

char *encode(const char *text)
{
    char *encoded = (char *)calloc(MAX_STRING_LEN, sizeof(char));
    int num_of_chars = 0;
    int text_length = (int)strlen(text);
    for (int i = 0; i < text_length - 1; i++)
    {
        num_of_chars++;
        if (text[i] != text[i + 1])
        {
            encode_letter(text[i], num_of_chars, encoded);
            num_of_chars = 0;
        }

        if (i + 1 == text_length - 1)
        {
            encode_letter(text[i + 1], ++num_of_chars, encoded);
            num_of_chars = 0;
        }
    }

    return encoded;
}

char *decode(const char *data)
{
    char *decoded = (char *)calloc(MAX_STRING_LEN, sizeof(char));
    char const *current = data;
    int number;
    while (*current != '\0')
    {
        number = read_number(&current);
        char ch = *current;
        decode_letter(ch, number, decoded);
        current++;
    }

    return decoded;
}

static void encode_letter(char ch, int num_of_chars, char *output)
{
    if (num_of_chars != 1)
    {
        char number[4];
        size_t number_len = convert_number_to_char_array(num_of_chars, number);
        strncat(output, number, number_len);
    }
    output[strlen(output)] = ch;
}

static void decode_letter(char ch, int num_of_chars, char *output)
{
    (void)ch;
    (void)num_of_chars;
    (void)output;
}

// returns length of the char array representation of the number
static size_t convert_number_to_char_array(int number, char *output)
{
    size_t length = (size_t)(log10(number)) + 1;
    char *current = &output[length - 1];
    do
    {
        *current-- = (number % 10) + '0';
        number /= 10;
    } while (number != 0);
    return length;
}

static int read_number(char const **p)
{
    int number = 0;
    while (isdigit(**p))
    {
        number *= 10;
        number += **p - '0';
        (*p)++; //TODO
    }

    return number != 0 ? number : 1;
}