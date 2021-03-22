#include <stdio.h>
#include <stdlib.h>
#include "Lab3_2_12.h"

int main() {
    unsigned int size = 1;
    unsigned int **latinSquare = NULL;

    printf("Enter the size of Latin square\n");
    size = getValidUInt();
    while (size > 100) {
        printf("Wrong input, too large matrix size\n"
               "Please, try again: ");
        size = getValidUInt();
    }

    latinSquare = getTwoDimensionalArray(size, size);
    if (!latinSquare) return 0;
    getLatinSquare(latinSquare, size);

    printMatrix(size, latinSquare);
    /*cast to (void **) is done to aVoid warnings from the compiler*/
    latinSquare = clearTwoTwoDimensionalArray((void **)latinSquare, size);
    return 0;    
}

unsigned int getValidUInt() {
    unsigned int temp;
    char goodCheck;

    while (!scanf("%u", &temp) || temp == 0 ||
          (scanf("%c", &goodCheck) && goodCheck != '\n')) {
        printf("Wrong input!\nPlease, try again: ");
        fflush(stdin);
    }
    return temp;
}

void printMatrix(unsigned int size, unsigned int **matrix) {
    unsigned int i, j;

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkNULL (void *ptr) {
    if (ptr == NULL) {
        printf("Error, there is no memory to allocate!\n");
        return 0;
    }
    return 1;
}

unsigned int **getTwoDimensionalArray(unsigned int rowsNumber,
                                      unsigned int columnsNumber) {
    unsigned int **array = NULL;
    unsigned int i;

    array = (unsigned int **)malloc(rowsNumber * sizeof(unsigned int *));
    if (!checkNULL(array)) return NULL;

    for (i = 0; i < columnsNumber; ++i) {
        array[i] =
            (unsigned int *)malloc(columnsNumber * sizeof(unsigned int *));
        if (!checkNULL(array[i])) return NULL;
    }
    return array;
}

void getLatinSquare(unsigned int **arrayToFill, unsigned int size) {
    unsigned int i, j, number;

    if (!arrayToFill) {
        printf("Wrong input! This array is NULL.");
        return;
    }

    for (i = 0; i < size; ++i) {
        number = i + 1;
        for (j = 0; j < size; ++j) {
            if (number == size + 1) number = 1;
            arrayToFill[i][j] = number;
            ++number;
        }
    }    
}

void *clearTwoTwoDimensionalArray(void **arrayToClean,
                                  unsigned int rowsNumber) {
    unsigned int i;
    
    if (!arrayToClean) {
        printf("This array is already clean.\n");
        return NULL;
    }
    
    for (i = 0; i < rowsNumber; ++i) free(arrayToClean[i]);
    free(arrayToClean);

    printf("Memory cleaned\n");
    return NULL;
}
