Lab2.13: Lab2.13.c Lab2.13.h
		gcc -ansi -pedantic Lab2.13.c -o Lab2.13

Lab2.13TEST: Lab2.13Test.c Lab2.13.c Lab2.13.h
		 gcc -ansi -pedantic Lab2.13.c Lab2.13Test.c -o Lab2.13Test -D TESTING -lm

Valgrind:
     echo "15\n" > input.txt
     valgrind ./Lab2.13 < input.txt
     valgrind ./Lab2.13Test
     
Linter:
    cpplint --filter=-readability/casting,-legal/copyright Lab2.13.c Lab2.13Test.c
    
TESTALL: Lab2.13 Lab2.13Test Valgrind Linter
