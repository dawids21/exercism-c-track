#include "pythagorean_triplet.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static uint16_t gcd(uint16_t a, uint16_t b);
static bool is_coprime(uint16_t a, uint16_t b);
static int find_next_triplet(triplet_t* triplet, uint16_t sum);

triplets_t* triplets_with_sum(uint16_t sum)
{
    triplets_t* triplets = (triplets_t*)malloc(sizeof(triplet_t));
    triplets->triplets = (triplet_t*)malloc(MAX_TRIPLET_NUM * sizeof(triplet_t));
    triplets->count = 0;
    triplet_t current_triplet;
    while(find_next_triplet(&current_triplet, sum) == 0)
    {
        int current_sum = current_triplet.a + current_triplet.b + current_triplet.c;
        if (sum % current_sum == 0)
        {
            /*
            Euclid's Formula generates only primitive triplets
            The rest are obtained by mulitplying primitives by some integer,
            therefore their sum by some integer.
            */
            int k = sum/current_sum;
            current_triplet.a = current_triplet.a * k;
            current_triplet.b = current_triplet.b * k;
            current_triplet.c = current_triplet.c * k;
            triplets->triplets[triplets->count] = current_triplet;
            triplets->count++;
        }
    }
    return triplets;
}

void free_triplets(triplets_t* triplets)
{
    if (triplets != NULL)
    {
        if (triplets->triplets != NULL)
        {
            free(triplets->triplets);
            triplets->triplets = NULL;
        }
        free(triplets);
        triplets = NULL;
    }
}

static uint16_t gcd(uint16_t a, uint16_t b)
{
    /*
    Here I used Euclidean Algorithm
    https://en.wikipedia.org/wiki/Euclidean_algorithm
    */
    while (b > 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

static bool is_coprime(uint16_t a, uint16_t b)
{
    return (gcd(a, b) == 1);
}

static int find_next_triplet(triplet_t* triplet, uint16_t sum)
{
/*
Here I used Euclid's Formula
https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
a = n^2 - m^2
b = 2mn
c = n^2 + m^2
where n > m and m and n are coprime and can't both be odd
I am genereting new triplets by incrementing n as long as:
a + b + c <= sum
n^2 - m^2 + 2mn + n^2 + m^2 <= sum
2n^2 + 2mn <= sum
n^2 + mn <= sum/2
n * (m+n) <= sum/2  This is first condition
At this point I am incrementing m and set n > m
m+n <= sum/2n
m < sum/2n - n
If this condition is false then I finished searching for triplets
*/
    static int n = 1;
    static int m = 1;
    int return_value = 0;
    do
    {
        if (n * (m+n) <= sum/2)
        {
            n++;
        }
        else
        {
            m++;
            n = m+1;
            if (m > sum/(2*n) - n)
            {
                return_value = -1;
            }
        }
    } while (!is_coprime(n, m) || (m % 2 != 0 && n % 2 != 0));
    if (return_value == 0)
    {
        triplet->a = (uint16_t)(2 * n * m);
        triplet->b = (uint16_t)(n*n - m*m);
        triplet->c = (uint16_t)(n*n + m*m);
        if (triplet->a > triplet->b)
        {
            uint16_t tmp = triplet->a;
            triplet->a = triplet->b;
            triplet->b = tmp;
        }
    }
    else if (return_value == -1)
    {
        m = 1;
        n = 1;
    }
    
    return return_value;
}