#include "nth_prime.h"
#include <stdint.h>
#include <stdbool.h>

static bool is_prime(uint32_t number);

uint32_t nth(uint32_t n)
{
    if (n < 1)
    {
        return 0;
    }

    uint32_t prime = 0;
    uint32_t num_of_prime = 0;
    for (uint32_t i = 2; num_of_prime != n; i++)
    {
        if (is_prime(i))
        {
            prime = i;
            num_of_prime++;
        }
    }

    return prime;
}

static bool is_prime(uint32_t number)
{
    bool prime = true;

    for (uint32_t factor = 2; factor < number; factor++)
    {
        if (number % factor == 0)
        {
            prime = false;
            break;
        }
    }

    return prime;
}