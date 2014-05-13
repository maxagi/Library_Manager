#include "Library_Manager.h"
#include<iostream>
//#include <vld.h>
using namespace std;
int main(){


	Borrower b1("max");
	Borrower b2("avi");

	cout <<"id of max is "<< b1.getId() <<endl<<"id of avi is " << b2.getId() << endl;


	Books_Container books;
	books.addBook(Book("c++", "yossi", 123));
	books.addBook(Book("c", "yossi", 1234));
	books.addBook(Book("c++", "someone else", 1234567));
	Book *found = books.findByISBN(123);
	
	list<Book*const>  booksByYossi = books.findByAuthor("yossi");
	list<Book*const>  booksOnCpp = books.findByTitle("c++");


	int x;
	cin >> x;
	return 0;
}