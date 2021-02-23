#include <stdio.h>

int main() {
    int i , j , k, counter = 0;
    /*Need to find first ten numbers, for which i^2 + j^2 = k^2 is true.
    Avoid repeating threes*/
    for (i = 1;; ++i) {
        for(j = i; j < 100; ++j) {
            for(k = i; k < 100; ++k) {
                if(i * i + j * j == k * k) {                   
                    printf("%d^2 + %d^2 = %d^2 \n", i, j, k);
                    ++counter;
                    if (counter == 10) return 0;
                    break;
                }
            }
        }
    }
    return 0;
}