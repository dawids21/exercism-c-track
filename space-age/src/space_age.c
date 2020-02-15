#include <stdio.h>
#include "space_age.h"
#define ONE_YEAR 31557600

float convert_planet_age(enum planets body, float seconds)
{
    switch(body)
    {
        case EARTH:
            return seconds/(1.0*ONE_YEAR);
            break;
        case VENUS:
            return seconds/(0.61519726*ONE_YEAR);
            break;
        case MERCURY:
            return seconds/(0.2408467*ONE_YEAR);
            break;
        case MARS:
            return seconds/(1.8808158*ONE_YEAR);
            break;
        case SATURN:
            return seconds/(29.447498*ONE_YEAR);
            break;
        case URANUS:
            return seconds/(84.016846*ONE_YEAR);
            break;
        case JUPITER:
            return seconds/(11.862615*ONE_YEAR);
            break;
        case NEPTUNE:
            return seconds/(164.79132*ONE_YEAR);
            break;
        default:
            return 0;
    }
}
