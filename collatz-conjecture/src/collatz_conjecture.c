#include "collatz_conjecture.h"
#define UNUSED(x) (void)(x)

int steps(int start)
{
    if (start <= 0) {
        return ERROR_VALUE;
    }

    int number = start;
    int step = 0;
    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
        } else {
            number = 3 * number + 1;
        }
        step++;
    }
    return step;
}
