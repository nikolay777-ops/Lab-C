#include "Lab1_2.h"

#include <stdio.h>
#include <assert.h>

void testCheckPythagoreanNumbers() {
	int result = checkPythagoreanNumbers(3, 4, 5);
	
	assert(result != 0);
}

int main() {
	testCheckPythagoreanNumbers();
	printf("Tests passed successfully\n");
	
	return 0;
}
