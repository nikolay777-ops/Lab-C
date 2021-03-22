#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Lab2.13.h"

void firstTest()
{
    int* x;
    int* y;
    int i;
    x = (int*)malloc(sizeof(int) * 6);
    assert(x);
    y = (int*)malloc(sizeof(int) * 6);
    assert(y);
    for (i = 0; i < 6; i++)
    {
        x[i] = 1;
        y[i] = 1;
    }
    assert(existingTriangleByCoord(x, y));
    free(x);
    free(y);
}
void secondTest()
{
    double* side;
    side = (double*)malloc(sizeof(int) * 3);
    assert(side);
    side[0] = 3.0;
    side[1] = 4.0;
    side[2] = 5.0;
    assert(existingTriangleBySides(side));
    free(side);
}
void thirdTest()
{   
    double* side;
    side = (double*)malloc(sizeof(int) * 3);
    assert(side);
    side[0] = 3.0;
    side[1] = 4.0;
    side[2] = 5.0;
    assert(perimeter(side));
    free(side);
}

int main()
{
    firstTest();
    secondTest();
    thirdTest();
    return 0;
}