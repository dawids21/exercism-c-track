#include "triangle.h"

bool is_equilateral(triangle_t triangle)
{
    return triangle.a == triangle.b && triangle.b == triangle.c;
}

bool is_isosceles(triangle_t triangle)
{
    return (triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c);
}

bool is_scalene(triangle_t triangle)
{
    return triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c;
}
