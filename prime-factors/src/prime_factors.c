#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t num_of_factors = 0;
    uint64_t input_number = n;
    for (uint64_t factor = 2; factor <= n; factor++)
    {
        if (input_number == 1)
        {
            break;
        }
        while (input_number % factor == 0)
        {
            factors[num_of_factors] = factor;
            num_of_factors++;
            input_number /= factor;
        }
    }
    return num_of_factors;
}