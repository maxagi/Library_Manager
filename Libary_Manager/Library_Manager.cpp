#include "Library_Manager.h"
#include <iostream>
#include <iomanip>
unsigned int Borrower::next_id = 1;
using namespace std;


/*
TODO:
ask Yossi if  we need to check if some one is waiting for
the book , and if yes , let him borrow it .
*/

bool Library_Manager::borrowBook(const unsigned long &ISBN, const unsigned int	&borrower_id){
	Borrower * bor = findBorrower_ById(borrower_id);
	Book * book = findBook_ByISBN(ISBN);

	if (book == NULL || bor == NULL) return false;

	if (book->isAvailable()){

		//don't allow borrower to borrow same book more than once
		if (bor->hasBook(book)) return false;
		bor->addToBorrowed(book);
		book->addBorrower(bor);
		book->decrease_available(1);
	}

	else{
		book->addToWaitingList(bor);
	}
	return true;
}



bool Library_Manager::returnBook(const unsigned long &ISBN, const unsigned int	&borrower_id){
	Borrower * bor = findBorrower_ById(borrower_id);
	Book * book = findBook_ByISBN(ISBN);

	if (book == NULL || bor == NULL) return false;

	book->removeBorrower(bor);
	bor->removeFromBorrowed(book);

	if (book->hasWaiters()){
		Borrower * newBorrower = book->popFirstInWaitingList();
		newBorrower->addToBorrowed(book);
		book->addBorrower(newBorrower);
		return true;
	}

	book->increase_available(1);
	return true;
}



bool Library_Manager::addBook(const string& title, const string& author, const long& ISBN, const unsigned int &howMany){

	Book * found_book = books.findByISBN(ISBN);

	if (found_book != NULL){

		if (found_book->getAuthor() != author || found_book->getTitle() != title)
			return false;

		found_book->increaseNum_of_copies(howMany);
		found_book->increase_available(howMany);
	}

	else{
		books.addBook(Book(title, author, ISBN));
	}
	return true;
}


/*
remove a single book  from the collection only if it is available.
*/
bool Library_Manager::removeBook(const long &ISBN, const unsigned int &howMany){

	Book * found_book = books.findByISBN(ISBN);

	if (found_book == NULL || found_book->getNum_of_available_copies() < howMany) return false;

	found_book->decreaseNum_of_copies(howMany);
	found_book->decrease_available(howMany);

	//if we removed the last copy , delete book from collection!
	if (found_book->getNum_of_copies() == 0)
		return books.removeBook(*found_book);

	return false;
}


void Library_Manager::reportBooksStatus(const string& byWhat)const 		 	{

	list<const Book*const > booksList = books.getAllBooks();
	list<const Book*const >::const_iterator citer = booksList.cbegin();

	string(Book::* getter) ()const = NULL;		//pointer to Book's getter  function

	if (byWhat == "title"){
		getter = &Book::getTitle;
	}
	else if (byWhat == "author"){
		getter = &Book::getAuthor;
	}
	else if (byWhat == "ISBN"){
		getter = &Book::getISBN_asString;
	}

	else return;

	cout << "****************************[Books Report]*******************************";
	cout << endl << endl
		<< setw(25) << byWhat
		<< setw(15) << "available"
		<< setw(10) << "total"
		<< setw(0) << endl;

	while (citer != booksList.cend()){
		cout
			<< setw(25) << ((*citer)->*getter)()
			<< setw(15) << (*citer)->getNum_of_available_copies()
			<< setw(10) << (*citer)->getNum_of_copies()
			<< setw(0) << endl;

		citer++;
	}
	cout << endl;
	cout << "*************************************************************************";
	cout << endl << endl;
}



bool Library_Manager::removeBorrower(const long &id){
	Borrower *found_borrower = findBorrower_ById(id);
	return found_borrower == NULL ? false : borrowers.removeBorrower(*found_borrower);
}


void Library_Manager::reportOnAllBorrowers(const string &byWhat)const {

	string(Borrower::* getter) ()const = NULL;		//pointer to Borrower's getter  function

	if (byWhat == "name"){
		getter = &Borrower::getName;
	}
	else if (byWhat == "ID"){
		getter = &Borrower::getId_asString;
	}
	else return;


	list <const Borrower*const > allBorrowers = borrowers.getAllBorrowes();
	cout << "**************************[Borrowers Report]*****************************";
	cout << endl << endl
		<< setw(25) << byWhat
		<< setw(0) << endl;

	for (list <const Borrower*const >::const_iterator citer = allBorrowers.cbegin(); citer != allBorrowers.cend(); ++citer)
	{
		if ((*citer)->hasBooks())
		{
			cout 
				<< setw(25) << ((*citer)->*getter)()
				<< setw(0) << endl;
		}
	}
	cout << endl;
	cout << "*************************************************************************";
	cout << endl << endl;
}