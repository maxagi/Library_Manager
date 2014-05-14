
#include "Books_Container.h"
#include "Borrowers_Container.h"


#include <list>
#include <string>



class Library_Manager{


public:
	~Library_Manager(){ /*	should be empty!!	*/ }
	Library_Manager(){}

	bool						borrowBook(const std::string ISBN, const unsigned int	borrower_id);
	bool						returnBook(const std::string ISBN, const unsigned int	borrower_id);

	bool						addBook(const std::string title, const std::string author, const long ISBN);
	bool						removeBook(const long ISBN);

	std::list<Book*const >		findBook_ByTitle(const std::string title)	{ return books.findByTitle(title); }
	std::list<Book*const >		findBook_ByAuthor(const std::string author)	{ return books.findByAuthor(author); }
	Book*						findBook_ByISBN(const long ISBN)			{ return books.findByISBN(ISBN); }
	void						reportBooksStatus();



	void						addBorrower(const std::string name);
	bool						removeBorrower(const long &id);
	Borrower*const 				findBorrower_ById(const long id)			{ return borrowers.findByID(id); }
	std::list<Borrower*const >	findBorrower_ByName(const std::string name)	{ return borrowers.findByName(name); }
	void						reportOnAllBorrowers();


private:

	Library_Manager(const Library_Manager & other);
	Library_Manager & operator=(const Library_Manager & other);

	Books_Container			books;		//all library books 
	Borrowers_Container		borrowers;	//all borrowers registered to the library

};

