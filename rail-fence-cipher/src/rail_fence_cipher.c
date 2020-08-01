#include "rail_fence_cipher.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const int MAX_RAIL_LENGTH = 30;

static void calculate_space_on_rails(size_t len_of_text, size_t rails,
                                     int *space_on_rail);

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
    int space_on_each_rail[rails]; // Create rails with apropriate
                                   // amount of space
    for (size_t i = 0; i < rails; i++)
    {
        space_on_each_rail[i] = 0;
    }
    calculate_space_on_rails(strlen(ciphertext), rails, space_on_each_rail);
    char *array_of_rails[rails];
    for (size_t i = 0; i < rails; i++)
    {
        array_of_rails[i] = (char *)calloc(space_on_each_rail[i] + 1,
                                           sizeof(char));
    }

    int current_start = 0; // Place text on each rail
    for (size_t i = 0; i < rails; i++)
    {
        memcpy(array_of_rails[i], &ciphertext[current_start], space_on_each_rail[i]);
        current_start += space_on_each_rail[i];
    }

    char *output = (char *)calloc(strlen(ciphertext) + 1, sizeof(char));
    char *pointer_to_rail[rails];
    for (size_t i = 0; i < rails; i++)
    {
        pointer_to_rail[i] = array_of_rails[i];
    }
    size_t num_of_current_rail = 0;
    bool forward = true;
    for (size_t i = 0; i < strlen(ciphertext); i++) //Read text from each rail
    {
        output[i] = *pointer_to_rail[num_of_current_rail];
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
    for (size_t i = 0; i < rails; i++)
    {
        free(array_of_rails[i]);
    }
    return output;
}

static void calculate_space_on_rails(size_t len_of_text, size_t rails,
                                     int *space_on_rail)
{
    size_t num_of_current_rail = 0;
    bool forward = true;
    for (size_t i = 0; i < len_of_text; i++)
    {
        space_on_rail[num_of_current_rail]++;

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
}