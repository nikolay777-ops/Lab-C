#include <math.h>
#include "Lab2.2.6.h"
#define PI 3.14159265
#define MAX_FACT 20
long double fact(int N)
{
    if (N < 0)
    {
        return 0;
    }
    if(N == 0)
    {
        return 1;
    }
    else
    {
        return N * fact(N - 1);
    }
}
double degToRad(double deg)
{
    return deg / 180 * PI;
}
double sinAlt(int n, double rad)
{
    int i;
    double value = 0.0;
    for (i = 1; i <= n; i++)
    {
        value += (pow(-1.0, i - 1) * pow(rad, 2 * i - 1) / fact(2 * i - 1));
    }
    return value;
}
#ifndef TESTING
int main()
{
    double sinAlternative;
    double sinNormal;
    double eps;
    double degrees;
    int i;
    printf("Please enter the angle in degrees: ");
    while(!scanf("%lf", &degrees))
    {
        fflush(stdin); 
        printf("Incorrect input. Please try again: ");
    }
    printf("Please enter the allowable error (it should be less than 1):");
    while (!scanf("%lf", &eps) && eps >= 1.0)
    {
        fflush(stdin);
        printf("Incorrcet input. Please try again: ");
    }
    sinNormal = sin(degToRad(degrees));
    for (i = 0; i < MAX_FACT; i++)
    {
        sinAlternative = sinAlt(i, degToRad(degrees));
        if (fabs(sinAlternative - sinNormal) < eps)
        {
            printf("Sin was calculated by the normal function: %lf\n", sinNormal);
            printf("Sin was calculated by Alternative method:%lf, and count of n is %d\n", sinAlternative, i);
            break;
        }
    }
    return 0;
}
#endif