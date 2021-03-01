#include <iostream>//Variant 9
#include <cmath>
using namespace std;

int numberIndex(int number);
void toElecimalNumber(int decimalNumber);

int main() {
	int ninefoldNumber = 1234567;
	int positionIndex = numberIndex(ninefoldNumber);
	//Transfer from nine base to decimal base
	int counter = 0;
	int decimalNumber = 0;
	for (int i = positionIndex; i >= 0; i--) {
		//Isolating individual digits in a number to transfer
		int numeral = ninefoldNumber/pow(10, i);
		for (int j = 0; j <= counter; j++ ) {
			numeral %= 10;
		}
		counter++;

		decimalNumber += numeral * pow(9, i);
	}
	cout << "Nine base number: " << ninefoldNumber << endl;
	cout << "Decimal base number: " << decimalNumber << endl;
	cout << "Elecimal base number: ";
	toElecimalNumber(decimalNumber);
	cout << endl;
}

//To transfer from one number system to another, you need a number index starting from 0
int numberIndex(int number) {
	int positionIndex = -1;
	do {
		number /= 10;
		positionIndex++;
	} while (number != 0);
	return positionIndex;
}

//"Transfer" from decimal to elecimal number system
void toElecimalNumber(int decimalNumber) {
	if (decimalNumber > 11) {
		toElecimalNumber(decimalNumber / 11);
	}
	decimalNumber %= 11;
	if (decimalNumber == 10) {
		cout << 'a';
	}
	else {
		cout << decimalNumber;
	}
}