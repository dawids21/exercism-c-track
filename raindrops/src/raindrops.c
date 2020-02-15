#include "raindrops.h"
#include <string.h>
#include <stdio.h>

void convert(char* dst, const int drops)
{
    if (drops % 3 == 0) strcat(dst, "Pling");
    if (drops % 5 == 0) strcat(dst, "Plang");
    if (drops % 7 == 0) strcat(dst, "Plong");
    if (*dst == 0) sprintf(dst, "%d", drops);
}
