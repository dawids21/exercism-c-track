#include "sieve.h"
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t * primes, size_t max_primes)
{
    //prime_numbers[i] == 0 <=> i is prime
    _Bool prime_numbers[limit+1];
    size_t num_of_primes = 0;
    memset(primes, 0, limit+1);
    //0 and 1 are not primes from definition
    prime_numbers[0] = 1;
    prime_numbers[1] = 1;

    for (uint32_t i = 2; i <= limit && num_of_primes < max_primes; i++)
    {
        if (prime_numbers[i] == 0)
        {
            primes[num_of_primes] = i;
            num_of_primes++;

            //every multiple of i is not prime
            for (uint32_t j = 2; i*j <= limit; j++)
            {
                prime_numbers[i*j] = 1;
            }
        }
    }
    return num_of_primes;
}