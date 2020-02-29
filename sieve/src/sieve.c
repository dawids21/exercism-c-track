#include "sieve.h"
#include <stdbool.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t * primes, size_t max_primes)
{
    bool prime_numbers[limit+1];
    memset(primes, 0, limit+1);
    for (uint32_t i = 2; i <= limit; i++)
    {
        if (prime_numbers[i] == false)
        {
            for (uint32_t j = 2; i*j <= limit; j++)
            {
                if (prime_numbers[i*j] == false)
                {
                    prime_numbers[i*j] = true;
                }
            }
        }
    }
    size_t num_of_primes = 0;
    for (uint32_t i = 2; i <= limit && num_of_primes < max_primes; i++)
    {
        if (prime_numbers[i] == false)
        {
            primes[num_of_primes] = i;
            num_of_primes++;
        }
    }
    return num_of_primes;
}