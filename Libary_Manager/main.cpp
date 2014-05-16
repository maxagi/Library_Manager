#include "Library_Manager.h"
#include<iostream>
//#include <vld.h>
using namespace std;
int main(){





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


	/*
	Books_Container books;
	books.addBook(Book("c++", "yossi", 123));
	books.addBook(Book("c", "yossi", 1234));
	books.addBook(Book("c++", "someone else", 1234567));
	Book *found = books.findByISBN(123);

	list<Book*const>  booksByYossi = books.findByAuthor("yossi");
	list<Book*const>  booksOnCpp = books.findByTitle("c++");
	*/





	int x;
	cin >> x;
	return 0;
}