#ifndef BORROWER_H
#define BORROWER_H

#include <string>
#include <list>
#include "book.h"
#include <sstream>
class Borrower{
public:
	~Borrower(){}
	Borrower(const std::string name) :name(name), id(next_id++){}

	//Borrower(const Borrower & other){}				<-- use default implementation
	//Borrower & operator=(const Borrower & other);		<-- use default implementation

	std::string					getName()					 const	 { return name; }
	void						setName(const std::string val)		 { name = val; }
	unsigned int				getId()						 const	 { return id; }
	std::string					getId_asString()			 const   { std::ostringstream ss; ss << id; return ss.str(); } 
	std::list<const Book*const >getBorrowedBooks()			 const	 { return borrowed_books; }
	int							getBorrowedBooksSize()		 const	 { return borrowed_books.size(); }	 // i think we will not need to use it ever.

	bool						hasBooks()					 const	 { return borrowed_books.size() > 0; }
	bool						hasBook(const Book * const b)const	 { return std::find(borrowed_books.begin(), borrowed_books.end(), b) != borrowed_books.end(); }
	void						addToBorrowed(Book*const  book)		 { borrowed_books.push_back(book); }
	void						removeFromBorrowed(Book*const  book) { borrowed_books.remove(book); }


	void						removeAllBooks()					 { borrowed_books.clear(); } // i think we will not need to use it ever.

private:
	static unsigned int				next_id;		//initialized in Library_Manager.cpp
	std::string						name;
	const unsigned int				id;
	std::list <const Book*const >	borrowed_books;

};

#endif 