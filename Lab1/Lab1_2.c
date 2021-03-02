#include <stdio.h>

#include "Lab1_2.h"

#ifndef TEST

int main() {
    int i , j , k, counter = 0;
    /*Need to find first ten numbers, for which i^2 + j^2 = k^2 is true.
    Avoid repeating threes*/
    for (i = 1;; ++i) {
        for(j = i; j < 100; ++j) {
            for(k = i; k < 100; ++k) {
                if(checkPythagoreanNumbers(i, j, k) != 0) {
                    counter++;
                } 
                if(counter == 10) return 0;
            }
        }
    }
    return 0;
}
#endif

int checkPythagoreanNumbers (int first, int second, int third) {
    return first * first + second * second == third * third; 
}
