#include<list>
#include<map>
#include"book.h"


class Books_Container{

public:
	~Books_Container(){/*should be empty!!*/ }
	Books_Container(){}

	bool				addBook(Book  book);	//return true if added , false if book with same isbn exists
	void				removeBook(Book  book)	{books.erase(book.getISBN());}

	Book*				findByISBN(const unsigned long isbn);
	std::list<Book*>	findByTitle(const std::string title);
	std::list<Book*>	findByAuthor(const std::string author);

	/*
	more functions
	*/


private:
	std::map<unsigned long, Book> books; 
};
