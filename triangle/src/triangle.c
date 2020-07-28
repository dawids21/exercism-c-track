#include "triangle.h"

bool is_correct_triangle(triangle_t triangle);

bool is_equilateral(triangle_t triangle)
{
    if (!is_correct_triangle(triangle)) {
        return false;
    }

    return triangle.a == triangle.b && triangle.b == triangle.c;
}

bool is_isosceles(triangle_t triangle)
{
    if (!is_correct_triangle(triangle)) {
        return false;
    }

    return (triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c);
}

bool is_scalene(triangle_t triangle)
{
    if (!is_correct_triangle(triangle)) {
        return false;
    }

    return triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c;
}

bool is_correct_triangle(triangle_t triangle)
{
    bool correct_triangle = true;
    if (triangle.a == 0 || triangle.b == 0 || triangle.c == 0) {
        correct_triangle = false;
    }
    if (triangle.a + triangle.b < triangle.c || triangle.a + triangle.c < triangle.b || triangle.b + triangle.c < triangle.a) {
        correct_triangle = false;
    }
    return correct_triangle;
}
