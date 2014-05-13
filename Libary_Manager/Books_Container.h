
#include<map>
#include"book.h"


class Books_Container{

public:
	~Books_Container(){/*should NOT be empty!!*/ }
	Books_Container(){}

	bool addBook(Book  book){
		return (books.insert(std::pair<unsigned long, Book>(book.getISBN(), book))).second;
	}

	void removeBook(Book  book){
		books.erase(book.getISBN());
	}

	Book findByISBN(unsigned long isbn){
		//return books[isbn];
	}
	


	/*
	more functions
	*/


private:
	std::map<unsigned long ,Book> books; // book-->ISBN
};

