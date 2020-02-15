#include "bob.h"
#include <string.h>
#include <ctype.h>

static _Bool check_upper(const char* line);
static _Bool contain_letters (const char* line);
static _Bool only_white_space (const char* line);
static _Bool end_with_question_mark (const char* line);

char* hey_bob(const char* greeting)
{
    if (check_upper(greeting) && contain_letters(greeting))
    {
        if (end_with_question_mark(greeting)) return "Calm down, I know what I'm doing!";
        else return "Whoa, chill out!";
    }
    if (end_with_question_mark(greeting)) return "Sure.";
    if (only_white_space(greeting)) return "Fine. Be that way!";
    return "Whatever.";
}


static _Bool check_upper(const char* line)
{
    for (unsigned int i = 0; i < strlen(line); i++)
    {
        if (isalpha(line[i]) && !isupper(line[i])) return 0;
    }
    return 1;
}

static _Bool contain_letters(const char* line)
{
    for (unsigned int i = 0; i < strlen(line); i++)
    {
        if (isalpha(line[i])) return 1;
    }
    return 0;
}

static _Bool only_white_space(const char* line)
{
    for (unsigned int i = 0; i < strlen(line); i++)
    {
        if (!isspace(line[i])) return 0;
    }
    return 1;
}

static _Bool end_with_question_mark(const char* line)
{
    for (int i = (strlen(line) - 1); i >= 0; i--)
    {
        if (line[i] == '?') return 1;
        else if (isalnum(line[i])) return 0;
    }
    return 0;
}
