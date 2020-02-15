#include "./difference_of_squares.h"

int square_of_sum(int number)
{
    int result=0;
    for (int i=1; i <= number; i++) result += i;
    return (result*result);
}

int sum_of_squares(int number)
{
    int result=0;
    for (int i=1; i <= number; i++) result += (i * i);
    return result;
}

int difference_of_squares(int number)
{
    return (square_of_sum(number) - sum_of_squares(number));
}
