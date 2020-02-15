#include "binary_search.h"

const int *binary_search(int value, const int* arr, size_t length)
{
    int first_element = 0;
    int last_element = length - 1;
    int current_element = last_element/2;
    while (first_element <= last_element)
    {
        if (arr[current_element] == value) return &arr[current_element];
        else if(arr[current_element] > value) last_element = current_element - 1;
        else first_element = current_element + 1;

        current_element = (last_element + first_element) / 2;
    }
    return NULL;
}
