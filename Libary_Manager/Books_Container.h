#include<list>
#include<map>
#include"book.h"


class Books_Container{

public:
	~Books_Container(){/*should be empty!!*/ }
	Books_Container(){}

	bool					addBook(Book  book);	//return true if added , false if book with same isbn exists
	void					removeBook(Book  book)	{books.erase(book.getISBN());}

	Book*const 				findByISBN(const unsigned long isbn)  ;
	std::list<Book*const >	findByTitle(const std::string title);
	std::list<Book*const >	findByAuthor(const std::string author);
	std::list<Book*const >	getBooksList();			//returns a list of all books 

private:
	std::map<unsigned long, Book> books; 
};
