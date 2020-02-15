#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

char *to_roman_numeral(unsigned int number)
{
    char* roman = (char*) calloc(ARRAY_SIZE, sizeof(char));
    char *symbols[NUM_OF_VALUES] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    unsigned int values[NUM_OF_VALUES] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0, size = (int)(sizeof(symbols)/sizeof(*symbols)); i < size && number != 0; i++)
    {
        while (number >= values[i])
        {
            if ((ARRAY_SIZE - strlen(roman)) > strlen(symbols[i]))
            {
                strcat(roman, symbols[i]);
                number -= values[i];
            }
            else break;
        }
    }
    return roman;
}
