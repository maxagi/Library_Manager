#ifndef BOOK_H
#define BOOK_H


#include <string>
#include <list>
#include <stack>
#include <queue>
class Borrower;
class Book{
public:
	~Book(){	/*should be empty!!*/	}
	Book(const std::string _title, const  std::string _author, const unsigned long _ISBN):
		title(_title), author(_author), ISBN(_ISBN), available(true), available_copies(1), num_of_copies(1){}

	//Book(const Book & other){}					<--	use deafault implementation
	//Book & operator=(const Book & other);			<--	use deafault implementation						


	unsigned long				getISBN() const					{ return ISBN; }

	std::string					getTitle() const				{ return title; }
	void						setTitle(std::string val)		{ title = val; }

	std::string					getAuthor() const				{ return author; }
	void						setAuthor(std::string val)		{ author = val; }

	bool						isAvailable() const				{ return available; }
	void						setAvailable(bool val)			{ available = val; }

	int							getNum_of_copies() const		{ return num_of_copies; }
	void						increaseNum_of_copies()			{ ++num_of_copies; }
	void						decreaseNum_of_copies()			{ --num_of_copies; }

	const std::list<Borrower*>	getBorrowers() const			{ return borrowers; }
	void						addBorrower(Borrower* const b);

	Borrower*					getFirstInWaitingList()const;
	void						addToWaitingList(Borrower*const b);


private:
	std::string					title;
	std::string					author;
	unsigned long				ISBN;
	bool						available;
	int							available_copies;
	int							num_of_copies;
	std::list<Borrower*>		borrowers;				// all users that borrowed the book
	std::queue<Borrower*>		waiting_list;			// users waiting for the book

};
#endif