#include <string>
#include <list>

class Book;

class Borrower{
public:
	~Borrower();
	Borrower(const std::string _name) :name(_name), id(next_id++){}
	Borrower(const Borrower & other);							// need to implement this ;
	Borrower & operator=(const Borrower & other);				// need to implement this also ;

	void				borrowBook(const Book & book);
	void				returnBook(const Book & book);

	std::string			getName() const					{ return name; }
	void				setName(const std::string val)	{ name = val; }

	const long			getId() const					{ return id; }

private:
	static	long		next_id;
	std::string			name;
	const long			id;
	std::list <Book*>	borrowed_books;
};