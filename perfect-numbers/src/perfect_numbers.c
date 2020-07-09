#include "perfect_numbers.h"
#include <math.h>

static int calculate_aliquot_sum(const int number);

kind classify_number(const int number)
{
    if (number < 1) {
        return ERROR;
    }
    kind type_of_number = ERROR;
    int aliquot_sum = calculate_aliquot_sum(number);
    if (aliquot_sum > number) {
        type_of_number = ABUNDANT_NUMBER;
    } else if (aliquot_sum == number) {
        type_of_number = PERFECT_NUMBER;
    } else {
        type_of_number = DEFICIENT_NUMBER;
    }
    return type_of_number;
}

static int calculate_aliquot_sum(const int number)
{
    int sum = 0;
    double max_possible_factor = sqrt(number);
    for (int i = 1; i <= max_possible_factor; i++) {
        if (number % i == 0 && i != number) {
            sum += i;
            if (i != max_possible_factor && i != 1) {
                sum += number / i;
            }
        }
    }
    return sum;
}
