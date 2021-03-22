CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab3_2_12.c
OBJ_TEST = Lab3_2_12.c Lab3_2_12_Test.c

Lab3_2_12: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab3_2_12

Lab3_2_12_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab3_2_12_Test -Dmain=_main $(LIBS)

CheckValgrind:
	echo "15\n" > input.txt
	valgrind ./Lab3_2_12 < input.txt
	valgrind ./Lab3_2_12_Test

CheckLinter:
	cpplint --filter=-readability/casting,-legal/copyright $(OBJ_TEST)

all: Lab3_2_12 Lab3_2_12_Test CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.exe