#include "perfect_numbers.h"

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
    for (int i = 1; i < number; i++) {
        if (i == number) {
            continue;
        }
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum;
}
