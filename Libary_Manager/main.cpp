#include "Library_Manager.h"
//#include <vld.h>
using namespace std;
int main(){


	Books_Container books;
	books.addBook(Book("c++", "yossi", 123));
	books.addBook(Book("c", "yossi", 1234));
	Book *found = books.findByISBN(123);
	
	list<Book*>  booksByYossi = books.findByAuthor("yossi");


	return 0;
}