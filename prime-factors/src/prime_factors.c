#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t num_of_factors = 0;
    uint64_t input_number = n;
    uint64_t current_factor = 2;
    while (input_number != 1)
    {
        while (input_number % current_factor == 0)
        {
            factors[num_of_factors] = current_factor;
            num_of_factors++;
            input_number /= current_factor;
        }
        current_factor++;
    }
    return num_of_factors;
}