#ifndef BOOKS_CONTAINER_H
#define BOOKS_CONTAINER_H



#include<list>
#include<string>
#include<map>
#include"book.h"


class Books_Container{

public:
	~Books_Container(){/*should be empty!!*/ }
	Books_Container(){}

	//return true if added , false if not (book with same isbn exists)
	bool	addBook(Book book);

	//return true if and only if the book was erased
	bool	removeBook(Book book){ return books.erase(book.getISBN()) == 1; }

	Book*const					findByISBN(const unsigned long isbn);
	const Book*const			findByISBN(const unsigned long isbn)const;


	std::list<Book*const >		findByTitle(const std::string title);
	std::list<const Book*const >findByTitle(const std::string title)const;

	std::list<Book*const >		findByAuthor(const std::string author);
	std::list<const Book*const >findByAuthor(const std::string author)const;


	std::list<const Book*const >getAllBooks()const;

private:

	Books_Container(const Books_Container & other);
	Books_Container & operator=(const Books_Container & other);

	std::map<unsigned long, Book> books;
};
#endif 