#ifndef BOOK_H
#define BOOK_H


#include <string>
#include <list>
#include <stack>
#include <queue>
class Borrower;
class Book{
public:
	~Book(){ /*should be empty!!*/ }
	Book(const std::string _title, const  std::string _author, const unsigned long _ISBN) :
		title(_title), author(_author), ISBN(_ISBN), available_copies(1), num_of_copies(1){}

	//Book(const Book & other){}				<-- use deafault implementation
	//Book & operator=(const Book & other);		<-- use deafault implementation


	unsigned long				getISBN() const						{ return ISBN; }

	std::string					getTitle() const					{ return title; }
	void						setTitle(const std::string &val)	{ title = val; }

	std::string					getAuthor() const					{ return author; }
	void						setAuthor(const std::string &val)	{ author = val; }

	bool						isAvailable() const					{ return available_copies>0; }
	//void						setAvailable(const bool val)		{ available = val; } // not needed

	int							getNum_of_copies() const			{ return num_of_copies; }
	void						increaseNum_of_copies()				{ ++num_of_copies; }
	void						decreaseNum_of_copies()				{ --num_of_copies; }

	int							getNum_of_available_copies() const	{ return available_copies; }
	void						increaseNum_of_available_copies()	{ ++available_copies; }
	void						decreaseNum_of_available_copies()	{ --available_copies; }

	const std::list<Borrower*>	getBorrowers() const				{ return borrowers; }
	void						addBorrower(Borrower* const b)		{ borrowers.insert(borrowers.end(), b); }
	void						removeBorrower(Borrower* const b)	{ borrowers.remove(b); }


	Borrower*					popFirstInWaitingList()				{ Borrower* b = waiting_list.front(); waiting_list.pop(); return b; }	//changed to remove next in line

	void						addToWaitingList(Borrower* const b) { waiting_list.push(b); }
	bool						hasWaiters()				const	{ return waiting_list.size() > 0; }						//added this method

private:
	std::string				title;
	std::string				author;
	unsigned long			ISBN;
	int						available_copies;
	int						num_of_copies;
	std::list<Borrower*>	borrowers;			// all users that borrowed the book
	std::queue<Borrower*>	waiting_list;		// users waiting for the book

};
#endif