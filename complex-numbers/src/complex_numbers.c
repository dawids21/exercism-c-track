#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real + b.real);
    res.imag = (a.imag + b.imag);
    return res;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real - b.real);
    res.imag = (a.imag - b.imag);
    return res;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real * b.real - a.imag * b.imag);
    res.imag = (a.imag * b.real + a.real * b.imag);
    return res;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t res;
    res.real = ((a.real * b.real + a.imag * b.imag) / (pow(b.real, 2.0) + pow(b.imag, 2.0)));
    res.imag = ((a.imag * b.real - a.real * b.imag) / (pow(b.real, 2.0) + pow(b.imag, 2.0)));
    return res;
}

double c_abs(complex_t x)
{
    return sqrt(pow(x.real, 2.0) + pow(x.imag, 2.0));
}

complex_t c_conjugate(complex_t x)
{
   x.imag *= -1;
   return x;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t res;
   res.real = (exp(x.real) * cos(x.imag));
   res.imag = (exp(x.real) * sin(x.imag));
   return res;
}
