#include "Lab1_2.h"

#include <stdio.h>
#include <assert.h>

void testCheckPythagoreanNumbers1() {
	int result = checkPythagoreanNumbers(3, 4, 5);
	
	assert(result != 0);
}

void testCheckPythagoreanNumbers2() {
	int result = checkPythagoreanNumbers(3, 4, 1);
	
	assert(result == 0);
}

int main() {
	testCheckPythagoreanNumbers1();
	testCheckPythagoreanNumbers2();
	printf("Tests passed successfully\n");
	
	return 0;
}
