#ifndef BOOKS_CONTAINER_H
#define BOOKS_CONTAINER_H



#include<list>
#include<map>
#include"book.h"


class Books_Container{

public:
	~Books_Container(){/*should be empty!!*/ }
	Books_Container(){}

	//return true if added , false if not (book with same isbn exists)
	bool							addBook(Book  book);

	//return true if and only if the book was erased 
	bool							removeBook(Book  book){ return books.erase(book.getISBN()) == 1; }

	Book*const 						findByISBN(const unsigned long isbn) ;
	std::list<Book*const >			findByTitle(const std::string title);
	std::list<Book*const >			findByAuthor(const std::string author);
	std::list<const Book*const >	getAllBooks()const ;			//returns a list of all books 

private:
	std::map<unsigned long, Book> books; 
};
#endif 