#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamming.h"

int compute(char *dna, char *rna)
{
    if (dna == NULL || rna == NULL || strlen(dna) != strlen(rna)) return ERROR;
    int counter = 0;
    for (int i = 0; dna[i] != '\0'; i++)
    {
        if (dna [i] != rna[i]) counter++;
    }
    return counter;
}
