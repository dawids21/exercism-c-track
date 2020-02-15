#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 50

bool is_paired(const char *str)
{
    char brackets[SIZE];
    char *ptr = brackets;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            *ptr = '(';
            ptr += 1;
        }
        else if (str[i] == '[')
        {
            *ptr = '[';
            ptr += 1;
        }
        else if (str[i] == '{')
        {
            *ptr = '{';
            ptr += 1;
        }
        else if (str[i] == ']')
        {
            if (ptr == brackets) return false;
            else
            {
                ptr -= 1;
                if (*ptr == '[') *ptr = '0';
                else return false;
            }
        }
        else if (str[i] == '}')
        {
            if (ptr == brackets) return false;
            else
            {
                ptr -= 1;
                if (*ptr == '{') *ptr = '0';
                else return false;
            }
        }
        else if (str[i] == ')')
        {
            if (ptr == brackets) return false;
            else
            {
                ptr -= 1;
                if (*ptr == '(') *ptr = '0';
                else return false;
            }
        }
    }
    if (ptr > brackets) return false;
    else return true;
}
