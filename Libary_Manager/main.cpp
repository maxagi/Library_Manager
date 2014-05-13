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
	Book *found = books.findByISBN(123);
	
	list<Book*>  booksByYossi = books.findByAuthor("yossi");


	int x;
	cin >> x;
	return 0;
}