#ifndef LAB3_2_12_H
#define LAB3_2_12_H

unsigned int getValidUInt();
void printMatrix(unsigned int size, unsigned int **matrix);
int checkNULL (void *ptr);
unsigned int **getTwoDimensionalArray(unsigned int rowsNumber,
                                      unsigned int columnsNumber);
void getLatinSquare(unsigned int **arrayToFill, unsigned int size);
void *clearTwoTwoDimensionalArray(void **arrayToClean,
                                  unsigned int rowsNumber);

#endif