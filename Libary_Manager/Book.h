#ifndef BOOK_H
#define BOOK_H


#include <string>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
class Borrower;
class Book{
public:
	~Book(){}
	Book(const std::string _title, const  std::string _author, const unsigned long _ISBN) :
		title(_title), author(_author), ISBN(_ISBN), available_copies(1), num_of_copies(1){}

	//Book(const Book & other){}				<-- use default implementation
	//Book & operator=(const Book & other);		<-- use default implementation



	unsigned long				getISBN()			const			 { return ISBN; }
	std::string					getISBN_asString()	const			 { std::ostringstream ss; ss << ISBN; return ss.str(); }
	std::string					getTitle()			const			 { return title; }
	void						setTitle(const std::string &val)	 { title = val; }

	std::string					getAuthor()			const			 { return author; }
	void						setAuthor(const std::string &val)	 { author = val; }

	bool						isAvailable()		const			 { return available_copies > 0; }

	unsigned int				getNum_of_copies()	const			 { return num_of_copies; }
	void						increaseNum_of_copies(unsigned int v){ num_of_copies += v; }
	void						decreaseNum_of_copies(unsigned int v){ num_of_copies -= v; }

	unsigned int				getNum_of_available_copies() const	 { return available_copies; }
	void						increase_available(unsigned int v)	 { available_copies += v; }
	void						decrease_available(unsigned int v)	 { available_copies -= v; }

	void						addBorrower(Borrower* const b)		 { borrowers.insert(borrowers.end(), b); }
	void						removeBorrower(Borrower* const b)	 { borrowers.remove(b); }
	std::list<const Borrower*const > getBorrowers() const			 { return borrowers; }


	Borrower*					popFirstInWaitingList()				 { Borrower* b = waiting_list.front(); waiting_list.pop(); return b; }
	void						addToWaitingList(Borrower* const b)  { waiting_list.push(b); }
	bool						hasWaiters()		const			 { return waiting_list.size() > 0; }

private:
	std::string				title;
	std::string				author;
	const unsigned long		ISBN;
	unsigned int			available_copies;
	unsigned int			num_of_copies;

	std::queue<Borrower*const >			waiting_list;				// users waiting for the book
	std::list<const Borrower*const >	borrowers;					// all users that borrowed the book

};
#endif