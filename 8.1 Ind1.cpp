//Variant 9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Workshop {
	char workshopNumber[31] = "00000";
	char productName[31] = "Product";
	int released = 0;
	int defect = 0;
	int workers = 0
};

Workshop* createDataBase(int& size, int& current);
void recreateDataBase(Workshop* oldData, int& size, int& current);

void addElement(Workshop* dataBase, int size, int& current);

void search(Workshop* dataBase, int& current);
void small�hoice(Workshop* dataBase, int index, int& current);
int charSearch(Workshop* dataBase, int& current);
int intSearch(Workshop* dataBase, int& current);

void deleteElement(Workshop* dataBase, int index, int& current);
void changeElement(Workshop* dataBase, int index);

void printDatabase(Workshop* dataBase, int current);
void printWorkshop(Workshop* oneWorkshop, int number);

void currentSize(int current);

void shekerSort(Workshop* dataBase, int current);

int enterWorkshop(Workshop* dataBase, int& size, int& current);

void menu(Workshop* dataBase, int size, int& current);

void mainDelimiter();
void sideDelimiter();
void enterDelimiter();
void menuDelimiter();

int main() {
	printf("Enter number of workshops: ");
	int size;
	scanf_s("%d", &size);

	int currentSize = 0;
	Workshop* dataBase = createDataBase(size, currentSize);
	menu(dataBase, size, currentSize);

	free(dataBase);
	return 0;
}

Workshop* createDataBase(int& size, int& current) {
	if (size < 0) {
		printf("Oops, wrong input\n");
		return NULL;
	}
	else {
		Workshop* ptrToData = (Workshop*)malloc(size * sizeof(Workshop));
		for (int i = 0; i < size; i++) {
			int temp;
			temp = enterWorkshop(ptrToData + i, size, current);
			if (temp == 0) {
				return ptrToData;
			}
		}
		return ptrToData;
	}
}

void recreateDataBase(Workshop* oldData, int& size, int& current) {
	Workshop* temp = (Workshop*)realloc(oldData, size * 2 * sizeof(Workshop));
	if (temp == NULL) {
		printf("Error, there is no space to realloc\n");
	}
	else {
		oldData = temp;
		size *= 2;
	}
}

void addElement(Workshop* dataBase, int size, int& current) {
	if (current == size) {
		recreateDataBase(dataBase, size, current);
	}
	enterWorkshop(dataBase + current, size, current);
}

void search(Workshop* dataBase, int& current) {
	printf("What do you want to search: string(1) or digit(2)? \n Answer: ");
	int answer;
	scanf("%d", &answer);

	int counter = 0;
	if (answer == 1) {
		counter = charSearch(dataBase, current);
	}
	else if (answer == 2) {
		counter = intSearch(dataBase, current);
	}
	else {
		printf("Oops, wrong input.\n");
		search(dataBase, current);
	}

	if (counter == 0) {
		printf("There is no such element.\n");
	}
	else {
		printf("\n%d matches were found.\n", counter);
	}
}

void small�hoice(Workshop* dataBase, int index, int& current) {
	printf("Delete(1)    Change(2)    Next(3)\n Answer: ");
	int answer;
	scanf("%d", &answer);
	sideDelimiter();
	switch (answer) {
	case 1:
		deleteElement(dataBase, index, current);
		break;
	case 2:
		changeElement(dataBase, index);
		break;
	case 3:
		break;
	default:
		printf("Oops, wrong input.");
		break;
	}
}

int charSearch(Workshop* dataBase, int& current) {

	printf("Enter string for search: ");
	char forSearch[31];
	scanf("%30s", &forSearch);
	int counter = 0;
	for (int index = 0; index < current; index++) {
		if (!strcmp(dataBase[index].workshopNumber, forSearch)) {
			printWorkshop(dataBase, index);
			small�hoice(dataBase, index, current);
			counter++;
		}
	}
	for (int index = 0; index < current; index++) {
		if (!strcmp(dataBase[index].productName, forSearch)) {
			printWorkshop(dataBase, index);
			small�hoice(dataBase, index, current);
			counter++;
		}
	}
	return counter;
}

int intSearch(Workshop* dataBase, int& current) {

	printf("Enter digit for search: ");
	int forSearch;
	scanf("%d", &forSearch);
	int counter = 0;

	for (int index = 0; index < current; index++) {
		if (dataBase[index].released == forSearch) {
			printWorkshop(dataBase, index);
			small�hoice(dataBase, index, current);
			counter++;
		}
	}
	for (int index = 0; index < current; index++) {
		if (dataBase[index].defect == forSearch) {
			printWorkshop(dataBase, index);
			small�hoice(dataBase, index, current);
			counter++;
		}
	}
	for (int index = 0; index < current; index++) {
		if (dataBase[index].workers == forSearch) {
			printWorkshop(dataBase, index);
			small�hoice(dataBase, index, current);
			counter++;
		}
	}
	return counter;
}

void deleteElement(Workshop* dataBase, int index, int& current) {
	if (index == -1) {
		printf("Enter number of element to delete.\n Number: ");
		scanf("%d", &index);

		if (index < 1 || index > current) {
			printf("There is no such element.");
		}
		else {
			index--;
		}
	}
	if (index == current - 1) {
		current--;
	}
	else {
		for (int i = index; i < current; i++) {
			dataBase[i] = dataBase[i + 1];
		}
		current--;
	}
}

void changeElement(Workshop* dataBase, int index) {
	enterDelimiter();
	printf("Database number %d\n\n", index + 1);

	printf("The workshop's number: ");
	scanf("%30s", dataBase[index].workshopNumber);

	printf("The product's name: ");
	scanf("%30s", dataBase[index].productName);

	printf("Released products: ");
	scanf("%d", &dataBase[index].released);

	printf("Defective products: ");
	scanf("%d", &dataBase[index].defect);

	printf("Number of workers: ");
	scanf("%d", &dataBase[index].workers);
	enterDelimiter();
}

void printDatabase(Workshop* dataBase, int current) {
	mainDelimiter();
	if (current == 0) {
		printf("There is no database.\n");
		sideDelimiter();
	}
	for (int i = 0; i < current; i++) {
		printWorkshop(dataBase, i);
	}
	mainDelimiter();
}

void printWorkshop(Workshop* dataBase, int number) {
	sideDelimiter();
	printf("Database number %d\n\n", number + 1);

	printf("The workshop number: %s\n ", dataBase[number].workshopNumber);

	printf("The product's name: %s\n", dataBase[number].productName);

	printf("Released products: %d\n", dataBase[number].released);

	printf("Defective products: %d\n", dataBase[number].defect);

	printf("Number of workers: %d\n", dataBase[number].workers);
	sideDelimiter();
}

void currentSize(int current) {
	sideDelimiter();
	printf("Current size: %d\n", current);
	sideDelimiter();
}

void shekerSort(Workshop* dataBase, int current) {
	int left = 0;
	int right = current - 1;
	int flag = 1;

	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (dataBase[i].released < dataBase[i + 1].released) {
				int temp = dataBase[i].released;
				dataBase[i].released = dataBase[i + 1].released;
				dataBase[i + 1].released = temp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (dataBase[i - 1].released < dataBase[i].released) {
				int temp = dataBase[i].released;
				dataBase[i].released = dataBase[i - 1].released;
				dataBase[i - 1].released = temp;
				flag = 1;
			}
		}
		left++;
	}
	printf("Sorting done.\n");
}

int enterWorkshop(Workshop* dataBase, int& size, int& current) {
	enterDelimiter();
	char answer[20];
	printf("Create another one? (yes/no): ");
	scanf(" %19s", &answer);

	if (!strcmp(answer, "yes")) {
		printf("    Workshop information\n");

		printf("The workshop's number: ");
		scanf("%30s", dataBase->workshopNumber);

		printf("The product's name: ");
		scanf("%30s", dataBase->productName);

		printf("Released products: ");
		scanf("%d", &dataBase->released);

		printf("Defective products: ");
		scanf("%d", &dataBase->defect);

		printf("Number of workers: ");
		scanf("%d", &dataBase->workers);
		current++;
	}
	else if (!strcmp(answer, "no")) {
		return 0;
	}
	else {
		printf("Oops, wrong input\n");
		return 0;
	}
	return 1;
	printf("\n");
	enterDelimiter();
}

void menu(Workshop* dataBase, int size, int& current) {
	menuDelimiter();
	printf("What do you want to do?\n");
	printf("Add new element   -- 1\n");
	printf("Search element    -- 2\n");
	printf("Delete element    -- 3\n");
	printf("Print database    -- 4\n");
	printf("Show current size -- 5\n");
	printf("Released sorting  -- 6\n");
	printf("Finish work       -- 7\n");
	printf("\nAction number: ");
	int menuAnswer;
	scanf("%d", &menuAnswer);
	menuDelimiter();
	switch (menuAnswer) {
	case 1:
		addElement(dataBase, size, current);
		menu(dataBase, size, current);
		break;
	case 2:
		search(dataBase, current);
		menu(dataBase, size, current);
		break;
	case 3:
		deleteElement(dataBase, -1, current);
		menu(dataBase, size, current);
		break;
	case 4:
		printDatabase(dataBase, current);
		menu(dataBase, size, current);
		break;
	case 5:
		currentSize(current);
		menu(dataBase, size, current);
		break;
	case 6:
		shekerSort(dataBase, current);
		menu(dataBase, size, current);
		break;
	case 7:
		printf("Good luck, have fun.\n");
		break;
	default:
		printf("\nWrong input.\n");
		menu(dataBase, size, current);
		break;
	}
}

void mainDelimiter() {
	for (int i = 0; i < 30; i++) {
		printf("+");
	}
	printf("\n");
}

void sideDelimiter() {
	for (int i = 0; i < 30; i++) {
		printf("-");
	}
	printf("\n");
}

void enterDelimiter() {
	for (int i = 0; i < 30; i++) {
		printf("~");
	}
	printf("\n");
}

void menuDelimiter() {
	for (int i = 0; i < 30; i++) {
		printf("*");
	}
	printf("\n");
}
