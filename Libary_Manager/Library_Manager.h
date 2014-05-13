
#include "Books_Container.h"
#include "Borrowers_Container.h"
#include "Borrower.h"

#include <list>
#include <string>

class Book;

class Library_Manager{


public:
	~Library_Manager(){ /*	should be empty!!	*/ }
	Library_Manager(){}

	bool					borrowBook(const std::string ISBN, const unsigned int	borrower_id);
	bool					returnBook(const std::string ISBN, const unsigned int	borrower_id);

	bool					addBook(const std::string title, const std::string author, const long ISBN);
	bool					removeBook(const long ISBN);
	std::list<Book&>		findBook_ByTitle(const std::string title)		const;
	std::list<Book&>		findBook_ByAuthor(const std::string author)		const;
	std::list<Book&>		findBook_ByISBN(const long ISBN)				const;
	void					reportBooksStatus(const bool status)			const;



	void					addBorrower(const std::string name);
	bool					removeBorrower(const long &id);
	Borrower&				findBorrower_ById(const long id)				const;
	std::list<Borrower&>	findBorrower_ByName(const std::string name)		const;
	void					reportOnAllBorrowers()							const;

	//for debugging only:
	void					printAllBorrowers();
	void					printAllBooks();

private:

	Library_Manager(const Library_Manager & other);
	Library_Manager & operator=(const Library_Manager & other);

	Books_Container			books;		//all library books 
	Borrowers_Container		borrowers;	//all borrowers registered to the library

};

