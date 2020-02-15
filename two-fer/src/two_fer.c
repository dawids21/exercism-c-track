#include "two_fer.h"
#include <stdio.h>

void two_fer(char* response, const char* name)
{
    if (name != NULL) sprintf(response, "%s %s%s", "One for", name, ", one for me.");
    else sprintf(response, "%s", "One for you, one for me.");
}
