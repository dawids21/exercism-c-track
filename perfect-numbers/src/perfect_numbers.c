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
    if (number == 1) {
        return 0;
    }

    // Every number > 1 has 1 as its factor
    int sum = 1;
    // If number is dividable by i then it is also dividable by number / i
    // so I can check factors up to a square root of the number
    double max_possible_factor = sqrt(number);
    for (int i = 2; i <= max_possible_factor; i++) {
        if (number % i == 0) {
            sum += i;

            // if i == max_possible_factor then i and number / i is the same
            if (i != max_possible_factor) {
                sum += number / i;
            }
        }
    }
    return sum;
}
