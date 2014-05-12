#include <string>
#include <list>
#include "book.h"

class Borrower{
public:
	~Borrower(){	/*needs to be empty */ }
	Borrower(const std::string name, const unsigned long id) :
		name(name), id(id){}

	std::string			getName()				const			{ return name; }
	void				setName(const std::string val)			{ name = val; }
	const long			getId()					const			{ return id; }
	std::list<Book*>	getBorrowedBooks()		const 			{ return borrowed_books; }
	int					getBorrowedBooksSize()	const			{ return borrowed_books.size(); }	 // i think we will not need to use it ever.


	void				addToBorrowed(Book*const  book)			{ borrowed_books.push_back(book); }
	void				removeFromBorrowed(Book*const  book)	{ borrowed_books.remove(book); }




	void				removeAllBooks()						{ borrowed_books.clear(); } // i think we will not need to use it ever.

private:
	std::string name;
	unsigned long id;
	std::list <Book*> borrowed_books;
};