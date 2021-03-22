#include "Lab2.2.6.h"
#include <assert.h>
void firstTest()
{
    int N;
    N = 5545;
    assert(fact(N) >= 0);
}
void secondTest()
{
    double sinAlternative;
    sinAlternative = sinAlt(5, degToRad(360));
    assert(sinAlternative);
}

int main()
{
    firstTest();
    secondTest();
    printf("Tests are done successfully!");
    getchar();
    return 0;
}