#include <iostream>
#include <string>
#include <cmath>
#include <iomanip.
#include <fstream>
#include <cstdlib>
using namespace std;

class Book {
private:
	string registrationNumber_ = "00000";
	string author_ = "Author";
	string title_ = "Title";
	int year_ = 0;
	string publisher_ = "Publisher";
	int pages_ = 0;
public:
	Book() = default;

	Book(string regNum, string author, string title, int year, string pblisher, int pages)
		: registrationNumber_(regNum), author_(author), title_(title),
		year_(fabs(year)), publisher_(pblisher), pages_(fabs(pages)) {
	}
	friend istream& operator>>(istream& in, Book& book);
	friend fstream& operator>>(fstream& in, Book& book);

	string getRegistrationNumber() const { return registrationNumber_; }
	void setRegistrationNumber(string registrationNumber) { registrationNumber_ = registrationNumber; }

	string getAuthor() const { return author_; }
	void setAuthor(string author) { author_ = author; }

	string getTitle() const { return title_; }
	void setTitle(string title) { title_ = title; }

	int getYear() const { return year_; }
	void setYear(int year) { year_ = fabs(year); }

	string getPublisher() const { return publisher_; }
	void setPublisher(string publisher) { publisher_ = publisher; }

	int getPages() const { return pages_; }
	void setPages(int pages) { pages_ = fabs(pages); }
};

istream& operator>>(istream& in, Book& book) {
	cout << "Registratio number: ";
	in.ignore();
	getline(in, book.registrationNumber_);
	cout << "Author: ";
	getline(in, book.author_);
	cout << "Title: ";
	getline(in, book.title_);
	cout << "Year: ";
	in >> book.year_;
	book.year_ = fabs(book.year_);
	cout << "Publisher: ";
	in.ignore();
	getline(in, book.publisher_);
	cout << "Pages: ";
	in >> book.pages_;
	book.pages_ = fabs(book.pages_);
	return in;
}

ostream& operator<<(ostream& out, const Book& b) {
	out << left;
	out << setw(10) << b.getRegistrationNumber() << '|';
	out << setw(30) << b.getAuthor() << '|';
	out << setw(30) << b.getTitle() << '|';
	out << setw(6) << b.getYear() << '|';
	out << setw(15) << b.getPublisher() << '|';
	out << setw(6) << b.getPages();
	return out;
}

//Special overloading for files
fstream& operator<<(fstream& out, const Book& b) {
	out << b.getRegistrationNumber() << "|";
	out << b.getAuthor() << "|";
	out << b.getTitle() << "|";
	out << b.getYear() << "|";
	out << b.getPublisher() << "|";
	out << b.getPages();
	return out;
}

fstream& operator>>(fstream& in, Book& book) {
	getline(in, book.registrationNumber_, '|');
	getline(in, book.author_, '|');
	getline(in, book.title_, '|');
	in >> book.year_;
	in.ignore();
	getline(in, book.publisher_, '|');
	in >> book.pages_;
	in.ignore();
	return in;
}

Book* createLibrary(fstream& filelib, int& capacity, int& length);
void resize(Book*& library, int& capacity);
void printLibrary(Book* library, int length);
void addBook(Book*& library, int& capacity, int& length);
void deleteBook(Book*& library, int& length);
void changeBook(Book*& library, int length);
void shakerSort(Book*& library, int length);
void yearSearch(Book* library, int length);
void showSize(int capacity, int length);
void menu(fstream& filelib, Book*& library, int& capacity, int& length);

int main() {
	int capacity = 0;
	int length = 0;

	fstream filelib;
	filelib.open("Library.txt");
	Book* library;

	if (filelib) {
		filelib.open("Library.txt", ios::in | ios::out | ios::app);
		filelib.clear();
		filelib.seekp(0, ios::beg);

		string counter;
		while (getline(filelib, counter, '\n')) {
			++length;
			++capacity;
		}

		library = new Book[length];
		filelib.clear();
		filelib.seekp(0, ios::beg);
		for (int i = 0; i < length; ++i) {
			filelib >> library[i];
		}
	}
	else {
		filelib.open("Library.txt", ios::in | ios::out | ios::trunc);
		library = createLibrary(filelib, capacity, length);
	}
	menu(filelib, library, capacity, length);

	filelib.clear();
	filelib.seekg(0, ios::beg);
	for (int i = 0; i < length; ++i) {
		filelib << library[i] << endl;
	}
	filelib.close();

	delete[] library;
	library = nullptr;
	return 0;
}

Book* createLibrary(fstream& filelib, int& capacity, int& length) {
	cout << "Enter number of books: ";
	cin >> capacity;
	capacity = fabs(capacity);

	Book* ptrLibrary = new Book[capacity];
	for (int i = 0; i < capacity; ++i) {
		cout << "   Element " << length + 1 << endl;
		cin >> ptrLibrary[i];
		++length;
	}
	shakerSort(ptrLibrary, length);
	for (int i = 0; i < length; ++i) {
		filelib << ptrLibrary[i] << endl;
	}
	return ptrLibrary;
}

void resize(Book*& library, int& capacity) {
	Book* temp = new Book[2 * capacity];
	for (int i = 0; i < capacity; ++i) {
		temp[i] = library[i];
	}
	capacity *= 2;
	delete[] library;
	library = temp;
}

void printLibrary(Book* library, int length) {
	cout << left;
	cout << setw(14) << "  Reg. number" << setw(31) << "Author" << setw(31) << "Title"
		<< setw(6) << "Year" << setw(17) << " Publisher" << setw(7) << "Pages" << endl;
	for (int i = 0; i < length; ++i) {
		cout << i + 1 << ") " << library[i] << endl;
	}
}

void addBook(Book*& library, int& capacity, int& length) {
	if (length >= capacity) {
		resize(library, capacity);
	}
	cout << "   Element " << length + 1 << endl;
	cin >> library[length];
	++length;
	shakerSort(library, length);
}

void deleteBook(Book*& library, int& length) {
	printLibrary(library, length);
	cout << "Enter the serial number of the book to delete: ";
	int index;
	cin >> index;
	if (index > length || index <= 0) {
		cout << "There is no such book." << endl;
	}
	else {
		--index;
		--length;
		for (int i = index; i < length; ++i) {
			library[i] = library[i + 1];
		}
	}
}

void changeBook(Book*& library, int length) {
	printLibrary(library, length);
	cout << "Enter the serial number of the book to change: ";
	int index;
	cin >> index;
	if (index > length || index <= 0) {
		cout << "There is no such book." << endl;
	}
	else {
		--index;
		cout << library[index] << "\nChange information about this book.\n";
		cin >> library[index];
		shakerSort(library, length);
	}
}

void shakerSort(Book*& library, int length) {
	int left = 0;
	int right = length - 1;
	int flag = 1;

	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (library[i].getAuthor() > library[i + 1].getAuthor()) {
				Book temp = library[i];
				library[i] = library[i + 1];
				library[i + 1] = temp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (library[i - 1].getAuthor() > library[i].getAuthor()) {
				Book temp = library[i];
				library[i] = library[i - 1];
				library[i - 1] = temp;
				flag = 1;
			}
		}
		left++;
	}
}

void yearSearch(Book* library, int length) {
	cout << "Enter the year from which you want to search for books: ";
	int answer;
	cin >> answer;
	if (answer < 0) {
		cout << "Oops, wrong year.";
	}
	else {
		fstream yearSortFile;
		yearSortFile.open("YearSorted.txt", ios::out);
		if (!yearSortFile) {
			cerr << "Uh oh, YearSorted.txt could not be opened!" << endl;
			exit(1);
		}
		cout << left;
		cout << setw(14) << "  Reg. number" << setw(31) << "Author" << setw(31) << "Title"
			<< setw(6) << "Year" << setw(17) << " Publisher" << setw(7) << "Pages" << endl;

		yearSortFile << "Entered year: " << answer << endl;
		yearSortFile << left << setw(14) << "  Reg. number" << setw(31) << "Author" << setw(31) << "Title"
			<< setw(6) << "Year" << setw(17) << " Publisher" << setw(7) << "Pages" << endl;

		for (int i = 0; i < length; ++i) {
			if (library[i].getYear() >= answer) {
				cout << i + 1 << ") " << library[i] << endl;
				yearSortFile << i + 1 << ") " << library[i] << endl;
			}
		}
		yearSortFile.close();
	}
}

void showSize(int capacity, int length) {
	cout << "Capacity: " << capacity << "\nLength: " << length << endl;
}

void menu(fstream& filelib, Book*& library, int& capacity, int& length) {
	cout << right << setw(11) << "MENU" << endl;
	cout << "1 -- Print library" << endl
		<< "2 -- Add book" << endl
		<< "3 -- Delete book" << endl
		<< "4 -- Change book" << endl
		<< "5 -- Search by year" << endl
		<< "6 -- Capacity and Length" << endl
		<< "7 -- Finish work" << endl;
	cout << "Action number: ";
	int answer;
	cin >> answer;
	switch (answer) {
	case 1:
		printLibrary(library, length);
		menu(filelib, library, capacity, length);
		break;
	case 2:
		addBook(library, capacity, length);
		filelib.clear();
		filelib.seekg(0, ios::beg);
		for (int i = 0; i < length; ++i) {
			filelib << library[i] << endl;
		}
		menu(filelib, library, capacity, length);
		break;
	case 3:
		deleteBook(library, length);
		//To delete and then overwrite a file
		filelib.open("Library.txt", ios::out);//delete 
		for (int i = 0; i < length; ++i) {
			filelib << library[i] << endl;
		}
		menu(filelib, library, capacity, length);
		break;
	case 4:
		changeBook(library, length);
		filelib.clear();
		filelib.seekg(0, ios::beg);
		for (int i = 0; i < length; ++i) {
			filelib << library[i] << endl;
		}
		menu(filelib, library, capacity, length);
		break;
	case 5:
		yearSearch(library, length);
		menu(filelib, library, capacity, length);
		break;
	case 6:
		showSize(capacity, length);
		menu(filelib, library, capacity, length);
		break;
	case 7:
		cout << "The meme at the end.\n            ('_')_/****  Vzhuh\n    int x;  /||        int definitely_good_name_for_variable;\n             /" << static_cast <char> (92) << endl;
		break;
	default:
		menu(filelib, library, capacity, length);
		break;
	}
}
