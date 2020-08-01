#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>

static const int MAX_RAIL_LENGTH = 30;

char *encode(char *text, size_t rails)
{
    char *output = (char *)calloc(strlen(text) + 1, sizeof(char));
    char individual_rails[rails][MAX_RAIL_LENGTH];
    return output;
}

char *decode(char *ciphertext, size_t rails)
{
    (void)ciphertext;
    (void)rails;
    return NULL;
}