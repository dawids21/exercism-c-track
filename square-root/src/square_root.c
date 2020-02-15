#include "square_root.h"
#include <math.h>

static float estimation(int number);

float squareRoot(int number)
{
  /*
    This is the implementation of Babylonian method
    For more information check: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
  */
    float root = estimation(number);
    while ((fabs(root*root - number)) > 0.000001)
      root = 0.5 * (root + number/root);
    return root;
}

static float estimation(int number)
{
  /*
    We need some inital value that is not so far from actual square root.
    For more information check: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Rough_estimation
  */
    int i = 0;
    while (number >= 100)
    {
        number /= 100;
        i++;
    }
    if (number >= 10)
      return 6.0 * pow(10, i);
    else
      return 2.0 * pow(10, i);
}
