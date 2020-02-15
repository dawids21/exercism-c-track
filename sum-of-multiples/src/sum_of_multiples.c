#include "sum_of_multiples.h"
#include <stdio.h>

int sum_of_multiples(const unsigned int* multiples, const int num_of_elements, const int max_number)
{
    if (multiples == NULL) return 0;
    int sum = 0;
    for (int i = 1; i < max_number; i++)
    {
        for (int j = 0; j < num_of_elements; j++)
        {
            if (multiples[j] && (i % multiples[j]) == 0)
            {
                sum += i;
                break;
            }
        }
    }
    return sum;
}
