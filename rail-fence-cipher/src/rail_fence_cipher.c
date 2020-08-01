#include "rail_fence_cipher.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const int MAX_RAIL_LENGTH = 30;

char *encode(char *text, size_t rails)
{
    char individual_rails[rails][MAX_RAIL_LENGTH];
    char *pointer_to_rail[rails];
    for (size_t i = 0; i < rails; i++)
    {
        memset(individual_rails[i], '\0', MAX_RAIL_LENGTH);
        pointer_to_rail[i] = individual_rails[i];
    }

    size_t num_of_current_rail = 0;
    bool forward = true;
    for (size_t i = 0; i < strlen(text); i++)
    {
        *pointer_to_rail[num_of_current_rail] = text[i];
        pointer_to_rail[num_of_current_rail]++;

        if (rails > 1)
        {
            num_of_current_rail += forward ? 1 : -1;
            if ((num_of_current_rail == rails - 1 && forward)
                || (num_of_current_rail == 0 && !forward))
            {
                forward = !forward;
            }
        }
    }

    char *output = (char *)calloc(strlen(text) + 1, sizeof(char));
    for (size_t i = 0; i < rails; i++)
    {
        strcat(output, individual_rails[i]); // concatenate all rails
    }
    return output;
}

char *decode(char *ciphertext, size_t rails)
{
    (void)ciphertext;
    (void)rails;
    return NULL;
}