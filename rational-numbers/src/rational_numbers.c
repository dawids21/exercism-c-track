#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

static int greatestCommonDivisor(int a, int b);

rational_t add(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    if (result.numerator != 0)
        result.denominator = r1.denominator * r2.denominator;
    else
        result.denominator = 0;
    return reduce(result);
}

rational_t subtract(rational_t r1, rational_t r2)
{
    r2.numerator *= -1;
    return add(r1, r2);
}

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.numerator;
    if (result.numerator != 0)
        result.denominator = r1.denominator * r2.denominator;
    else
        result.denominator = 0;
    return reduce(result);
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    return reduce(result);
}

rational_t absolute(rational_t r)
{
    rational_t result;
    result.numerator = abs(r.numerator);
    result.denominator = abs(r.denominator);
    return reduce(result);
}

rational_t exp_rational(rational_t r, int exponent)
{
    rational_t result;
    result.numerator = pow(r.numerator, exponent);
    result.denominator = pow(r.denominator, exponent);
    return reduce(result);
}

float exp_real(unsigned int x, rational_t exponent)
{
    float result;
    if (exponent.numerator > 0)
        result = pow(pow(x, exponent.numerator), 1.0/exponent.denominator);
    else
        result = 1.0/(pow(pow(x, exponent.numerator * -1), 1.0/exponent.denominator));
    return result;
}

rational_t reduce(rational_t r)
{
    rational_t result;
    if (r.numerator != 0)
    {
        int gcd = greatestCommonDivisor(r.numerator, r.denominator);
        result.numerator = r.numerator/gcd;
        result.denominator = r.denominator/gcd;
    }
    else
    {
        result.numerator = 0;
        result.denominator = 1;
    }

    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return result;
}

static int greatestCommonDivisor(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}