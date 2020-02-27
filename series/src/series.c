#include "series.h"
#include <stdlib.h>
#include <string.h>

series_results_t series(char *input_text, unsigned int substring_length)
{
    series_results_t series;
    series.substring_count = 0;

    //case if substring_lenght is equal to 0
    if (substring_length == 0)
    {
        series.substring = 0;
        return series;
    }

    //allocate memory for array of pointers to substrings
    series.substring = (char**)malloc(
        (strlen(input_text) - substring_length + 1) * sizeof(char*));

    //allocate memory for each substring and save pointer in array
    for (unsigned int i = 0; i < strlen(input_text) - substring_length + 1; i++)
    {
        series.substring[i] = (char*)malloc(
            (substring_length+1) * sizeof(char));

        //after every allocation copy the substring from input
        memcpy(series.substring[i], &input_text[i], substring_length * sizeof(char));
        
        //each string ends with \0
        series.substring[i][substring_length] = '\0';
        series.substring_count++;
    }
    return series;
}