#include "wordy.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

enum operations {ADD, SUB, MUL, DIV};

static int search_for_operation(const char* string);
static int shift_question(int operation);

bool answer(const char* question, int* result)
{
    bool was_first_number = false;
    bool reading_number = false;
    int number = 0;
    int operation = ADD;
    *result = 0;

    for (; *question != '\0'; question++)
    {
        if (was_first_number && !reading_number)
        {
            operation = search_for_operation(question);
            question += shift_question(operation);
        }

        if ((isdigit(*question) || *question == '-') && !reading_number)
        {
            reading_number = true;
            number = atoi(question);
        }

        else if (!isdigit(*question) && reading_number)
        {
            reading_number = false;
            if(!was_first_number) was_first_number = true;
        }

        if (was_first_number && !reading_number)
        {
            switch (operation)
            {
            case ADD:
                *result += number;
                break;
            case SUB:
                *result -= number;
                break;
            case MUL:
                *result *= number;
                break;
            case DIV:
                *result /= number;
                break;
            default:
                return false;
                break;
            }
        }
    }
    if (!was_first_number) return false;
    return true;
}

static int search_for_operation(const char* question)
{
    if (strstr(question, "plus") == question) return ADD;
    else if (strstr(question, "minus") == question) return SUB;
    else if (strstr(question, "multiplied by") == question) return MUL;
    else if (strstr(question, "divided by") == question) return DIV;
    else return -1;
}

static int shift_question(int operation)
{
    switch (operation)
    {
    case ADD:
        return 5;
    case SUB:
        return 6;
    case MUL:
        return 14;
    case DIV:
        return 11;
    default:
        return 0;
    }
}
