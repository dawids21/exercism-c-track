#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>

char* count(const char* dna)
{
    char* counted;
    int nucleotides[4] = {0,0,0,0};
    counted = malloc(sizeof(char) * 25);
    for (int i = 0; dna[i] != '\0'; i++)
    {
        switch(dna[i])
        {
        case 'A':
            nucleotides[0]++;
            break;
        case 'C':
            nucleotides[1]++;
            break;
        case 'G':
            nucleotides[2]++;
            break;
        case 'T':
            nucleotides[3]++;
            break;
        default:
            return counted;
        }
    }
    sprintf(counted, "A:%d C:%d G:%d T:%d", nucleotides[0], nucleotides[1], nucleotides[2], nucleotides[3]);
    return counted;
}
