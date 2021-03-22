#include <stdio.h>
#include <assert.h>
#include "Lab3_2_12.h"

void testCheckNULL() {
    int test = 0;
    int *testPtr = &test;

    assert(checkNULL(NULL) == 0);
    assert(checkNULL(testPtr) == 1);
    printf("NULL check test completed.\n");
}

void testMemoryManagement() {
    unsigned int **testArray = getTwoDimensionalArray(12, 12);
    assert(testArray != NULL);

    testArray = clearTwoTwoDimensionalArray((void **)testArray, 12);
    assert(testArray == NULL);

    testArray = clearTwoTwoDimensionalArray((void **)testArray, 12);
    assert(testArray == NULL);
    printf("Memory management test completed.\n");
}

#undef main

int main() {
    printf("Tests start.\n");
    testCheckNULL();
    testMemoryManagement();
    printf("All tests are completed.\n");
    return 0;
}
