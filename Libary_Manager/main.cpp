#include "Library_Manager.h"
#include<iostream>
using namespace std;
//#include <vld.h>



static void printBooks(std::list< Book*const > bookList){
	std::list< Book* const>::const_iterator citer = bookList.cbegin();
	while (citer != bookList.cend())
		(*citer++)->print();
}

static void printBorrowers(std::list<Borrower* const >  borrowers) {
	std::list<Borrower* const>::iterator citer = borrowers.begin();
	while (citer != borrowers.cend())
		(*citer++)->print();
}



#define husam
int main(){




#ifdef max



	Library_Manager manager;
	manager.addBorrower("max");
	manager.addBorrower("husam");
	manager.addBorrower("yossi");
	manager.addBorrower("danny");


	manager.addBook("c++", "yossi", 123, 1);
	manager.addBook("c++", "yossi", 123, 1);
	manager.addBook("c++", "david", 222, 1);
	manager.addBook("c", "yossi", 12345, 1);
	manager.addBook("kipa aduma ba yaar", "moshe cohen", 123456789, 1);
	manager.reportBooksStatus("author");


	manager.borrowBook(123, 1);
	manager.borrowBook(123, 2);
	manager.borrowBook(123, 3);
	manager.borrowBook(123456789, 4);

	manager.reportOnAllBorrowers("ID");
	manager.returnBook(123, 1);
	manager.returnBook(123, 2);
	manager.reportOnAllBorrowers("name");

	list<Book*const > yossiBooks = manager.findBook_ByAuthor("yossi");




	int x;
	cin >> x;
	return 0;

#endif  //max

#ifdef husam

	Library_Manager lib;
	unsigned int c, c1;
	bool cont = true;
	string str1, str2, str3, str4;
	int int1, int2;
	long long1;
	std::list< Book*const > books;
	std::list<Borrower*const > borrowers;

	Borrower* borr;

	while (cont){
		cout << "\n";
		cout << " Library system " << endl
			<< " 0: add a new book to the library" << endl
			<< " 1: remove a book" << endl
			<< " 2: Update a book" << endl
			<< " 3: Search for a book" << endl
			<< " 4: Report on status of all books" << endl
			<< " 5: Add borrower record" << endl
			<< " 6: Search borrower record " << endl
			<< " 7: Update borrower record " << endl
			<< " 8: Report on all borrowers" << endl
			<< endl
			<< " 9: borrow book" << endl
			<< " 10: return book" << endl << endl
			<< " 11: quit" << endl << endl
			<< "Enter your choice : " << endl;
		cin >> c;


		switch (c) {
		case 0:
			cin.sync();
			cout << "please enter the name of the book and then press enter" << endl;
			getline(cin, str1);
			cout << "please enter the name of author and then press enter" << endl;
			getline(cin, str2);
			cout << "please enter the ISBN number of the book and then press enter" << endl;
			cin >> long1;
			cout << "please enter the number of copies of the book and then press enter" << endl;
			cin >> int1;

			if (long1 > 0 && int1 > 0){ // check if ISBN in valid
				if (!lib.addBook(str1, str2, long1, int1))
					cout << "The book wasn't added due to error" << endl;
			}
			else
				cout << "the number of copies and ISBN have to be numbers greater then 0" << endl;
			break;

		case 1:
			cout << "please enter the ISBN of the book and then press enter" << endl;
			cin >> long1;
			if (!lib.removeBook(long1)){
				cout << "Error: there isn't a book with the entered ISBN or the book is borrowed" << endl;
			}

		case 2:
			cout << "please enter the ISBN of the book and then press enter" << endl;
			cin >> long1;
			cout << "0: update title" << endl;
			cout << "1: update author" << endl;
			cin >> c1;
			switch (c1) {
			case 0:
				cin.sync();
				cout << "please enter the new title of the book" << endl;
				getline(cin, str1);
				if (!lib.updateBook(long1, str1, c1)){
					cout << "Error: there isn't a book with the entered ISBN or the book is borrowed" << endl;
				}
				break;
			case 1:
				cin.sync();
				cout << "please enter the new author name of the book" << endl;
				getline(cin, str1);
				if (!lib.updateBook(long1, str1, c1)){
					cout << "Error: there isn't a book with the entered ISBN or the book is borrowed" << endl;
				}
				break;
			}
			break;

		case 3:
			cout << "0: search by title" << endl;
			cout << "1: search by author" << endl;
			cout << "2: search by ISBN" << endl;
			cin >> c1;

			switch (c1) {
			case 0:
				cin.sync();
				cout << "please enter the title of the book" << endl;
				getline(cin, str1);
				books = lib.findBook_ByTitle(str1);
				cout << "Search results:" << endl;
				printBooks(books);
				break;

			case 1:
				cin.sync();
				cout << "please enter the author name of the book" << endl;
				getline(cin, str1);
				books = lib.findBook_ByAuthor(str1);
				cout << "Search results:" << endl;
				printBooks(books);
				break;

			case 2:
				cout << "please enter the ISBN of the book" << endl;
				cin >> long1;
				Book*const book = lib.findBook_ByISBN(long1);
				cout << "Search results:" << endl;
				book->print();
				break;
			}
			break;

		case 4:
			cin.sync();
			cout << "0: report  by ISBN" << endl;
			cout << "1: report by title" << endl;
			cin >> c1;
			switch (c1) {
			case 0:
				cin.sync();
				cout << "enter ISBN:";
				getline(cin, str1);
				lib.reportBooksStatus(str1, "isbn");
				break;

			case 1:
				cin.sync();
				cout << "enter title:";
				getline(cin, str1);
				lib.reportBooksStatus(str1,"title");
				break;
			}
			break;

		case 5:
			cin.sync();
			cout << "please enter borrower name" << endl;
			getline(cin, str1);
			lib.addBorrower(str1);
			break;

		case 6:
			cout << "0: search borrower by ID" << endl;
			cout << "1: search borrower by name" << endl;
			cin >> c1;
			switch (c1) {
			case 0:
				cout << "please enter the ID of the borrower" << endl;
				cin >> int1;
				borr = lib.findBorrower_ById(int1);
				cout << "Search results:" << endl;
				borr->print();
				break;

			case 1:
				cin.sync();
				cout << "please enter borrower name" << endl;
				getline(cin, str1);
				borrowers = lib.findBorrower_ByName(str1);
				cout << "Search results:" << endl;
				printBorrowers(borrowers);
				break;
			}
			break;

		case 7:
			cout << "please enter borrower ID" << endl;
			cin >> int1;

			cout << "0: update borrower name" << endl;
			cout << "1: borrow book" << endl;
			cout << "2: return book" << endl;
			cin >> c1;

			switch (c1) {
			case 0:
				cin.sync();
				cout << "please enter borrower new name" << endl;
				getline(cin, str1);
				if (!lib.updateBorrowerName(int1, str1))
					cout << "Error: there isn't a borrower with the entered ID" << endl;
				break;
			case 1:
				cout << "please enter book ISBN" << endl;
				cin >> long1;
				lib.borrowBook(long1, int1);
				break;
			case 2:
				cout << "please enter book ISBN" << endl;
				cin >> long1;
				lib.returnBook(long1, int1);
				break;
			}
			break;

		case 8:
			cin.sync();
			cout << "please enter by what would you like to see borrower status name, ID" << endl;
			getline(cin, str1);
			lib.reportOnAllBorrowers(str1);
			break;

		case 9:
			cin.sync();
			cout << "borrower ID:" << endl;
			cin >> int1;
			cout << "books ISBN:" << endl;
			cin >> long1;
			int2 = lib.borrowBook(long1, int1);
			cout << endl;
			if (int2 < 0) cout << "error borrowing book!" << endl;
			else if (int2 == 0) cout << "book borrowed" << endl;
			else cout << "entered to book's waiting list , place= " << int2 << endl;

			break;

		case 10:
			cin.sync();
			cout << "borrower ID:" << endl;
			cin >> int1;
			cout << "books ISBN:" << endl;
			cin >> long1;
			cout << endl;
			int2 = lib.returnBook(long1, int1);
			if (int2 == -1)cout << "error returning book!" << endl;
			else cout << "book returned" << endl;
			break;

		default:
			cont = false;
		}

	}


#endif // husam
}