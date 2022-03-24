#include <stdio.h>
#include <math.h>
#include "equation.h"

int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2)
{
    /* Только квадратные уравнения */
    if (a == 0)
        return -1;

    double d = b * b - 4 * a * c;

    if (d >= 0)
    {
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);

        if (d == 0)
            return 1;
        return 2;
    }
    return 0;
}
