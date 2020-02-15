#include "allergies.h"
#include "string.h"

bool is_allergic_to(allergen_t allergen, unsigned int score)
{
    return (1 << allergen) & score;
}

allergen_list_t get_allergens(unsigned int score)
{
    allergen_list_t allergens;
    memset(&allergens, 0, sizeof(allergens));
    for (int i = 0; i < ALLERGEN_COUNT; i++)
    {
        if ((1 << i) & score)
        {
            allergens.allergens[i] = true;
            allergens.count++;
        }
    }
    
    return allergens;
}