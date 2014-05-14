#ifndef BORROWER_H
#define BORROWER_H

#include <string>
#include <list>
#include "book.h"

class Borrower{
public:
	~Borrower(){	/*needs to be empty */ }
	Borrower(const std::string name) :name(name), id(next_id++){}	// need to initialize next_id in .cpp file ! like this: unsigned int Borrower::next_id =1

	std::string			getName()				const			{ return name; }
	void				setName(const std::string val)			{ name = val; }
	unsigned int		getId()					const			{ return id; }
	std::list<Book*>	getBorrowedBooks()		const 			{ return borrowed_books; }
	int					getBorrowedBooksSize()	const			{ return borrowed_books.size(); }	 // i think we will not need to use it ever.

	bool				hasBooks()				const			{ return borrowed_books.size() > 0; }
	void				addToBorrowed(Book*const  book)			{ borrowed_books.push_back(book); }
	void				removeFromBorrowed(Book*const  book)	{ borrowed_books.remove(book); }




	void				removeAllBooks()						{ borrowed_books.clear(); } // i think we will not need to use it ever.

private:
	static unsigned int next_id;
	std::string name;
	unsigned int  id;
	std::list <Book*> borrowed_books;
};

#endif 