#include "series.h"
#include <stdlib.h>
#include <string.h>

series_results_t series(char *input_text, unsigned int substring_length)
{
    series_results_t series;
    series.substring_count = 0;
    series.substring = (char**)malloc(
        (strlen(input_text) - substring_length + 1) * sizeof(char*));
    for (unsigned int i = 0; i < strlen(input_text) - substring_length + 1; i++)
    {
        series.substring[i] = (char*)malloc(
            (substring_length+1) * sizeof(char));
        memcpy(series.substring[i], &input_text[i], substring_length * sizeof(char));
        series.substring[i][substring_length] = '\0';
        series.substring_count++;
    }
    return series;
}