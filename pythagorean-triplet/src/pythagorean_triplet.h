#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

#include <stdint.h>

#define MAX_TRIPLET_NUM 20

typedef struct
{
    uint16_t a;
    uint16_t b;
    uint16_t c;
} triplet_t;

typedef struct
{
    triplet_t* triplets;
    uint16_t count;
} triplets_t;

triplets_t* triplets_with_sum(uint16_t sum);
void free_triplets(triplets_t* triplets);

#endif
