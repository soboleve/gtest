#include <stdio.h>

#include "equation.h"

int main()
{
    double x1, x2;

    solveQuadraticEquation(2,3,-3,&x1,&x2);

    printf("x1=%lf\nx2=%lf\n",x1,x2);

    return 0;
}
