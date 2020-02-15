#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna)
{
    int len = strlen(dna) + 1;
    char *rna = (char*) malloc(len);
    for (int i = 0; dna[i] != '\0'; i++)
    {
        switch (dna[i])
        {
        case 'A':
            rna[i] = 'U';
            break;
        case 'C':
            rna[i] = 'G';
            break;
        case 'G':
            rna[i] = 'C';
            break;
        case 'T':
            rna[i] = 'A';
            break;
        default:
            free(rna);
            return NULL;
        }
    }
    rna[len - 1] = '\0';
    return rna;
}
