#include "rail_fence_cipher.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void calculate_space_on_rails(size_t len_of_text, size_t rails,
                                     int *space_on_rail);

char *encode(char *text, size_t rails)
{
    int space_on_each_rail[rails]; // Calculate how much space is needed
                                   // on each rail
    memset(space_on_each_rail, 0, rails * sizeof(int));
    calculate_space_on_rails(strlen(text), rails, space_on_each_rail);
    char *array_of_rails[rails];
    char *pointer_to_rail[rails];
    for (size_t i = 0; i < rails; i++)
    {
        array_of_rails[i] = (char *)calloc(space_on_each_rail[i] + 1,
                                           sizeof(char)); //Create rails
        pointer_to_rail[i] = array_of_rails[i];           // Get pointer to each rail
                                                          // for iterations
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
        strcat(output, array_of_rails[i]); // concatenate all rails
    }

    for (size_t i = 0; i < rails; i++)
    {
        free(array_of_rails[i]);
    }

    return output;
}

char *decode(char *ciphertext, size_t rails)
{
    int space_on_each_rail[rails]; // Calculate how much space is needed
                                   // on each rail
    memset(space_on_each_rail, 0, rails * sizeof(int));
    calculate_space_on_rails(strlen(ciphertext), rails, space_on_each_rail);

    char *array_of_rails[rails];
    char *text_for_rail = ciphertext;
    char *pointer_to_rail[rails];
    for (size_t i = 0; i < rails; i++)
    {
        array_of_rails[i] = (char *)calloc(space_on_each_rail[i] + 1,
                                           sizeof(char)); //Create rails
        memcpy(array_of_rails[i], text_for_rail,
               space_on_each_rail[i]); // Place text on each rail
        text_for_rail += space_on_each_rail[i];
        pointer_to_rail[i] = array_of_rails[i]; // Get pointer to each rail
                                                // for iterations
    }

    char *output = (char *)calloc(strlen(ciphertext) + 1, sizeof(char));
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