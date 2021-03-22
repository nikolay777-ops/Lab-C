#ifndef LAB2_13_H
#define LAB2_13_H
#include <math.h>
#include <stdbool.h>
#include <float.h>
void printInf();
void countingSide(int* x, int* y, double* side);
int existingTriangleByCoord(int* x, int* y);
bool existingTriangleBySides(double* side);
void maxValue(double* site);
void typeTriangle(double* site);
void clear(void);
void getCoordofTriangle(int* x, int* y);
float perimeter(double* site);
void square(double* side);

#endif