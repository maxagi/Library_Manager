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

	if (book == NULL||bor==NULL) return false;

	if (book->isAvailable()){
		bor->addToBorrowed(book);					//what if already borrowed same book ?/
		book->addBorrower(bor);
		book->decreaseNum_of_available_copies();
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

	book->increaseNum_of_available_copies();
	return true;
}



bool Library_Manager::addBook(const string& title, const string& author, const long& ISBN){

	Book * found_book = books.findByISBN(ISBN);

	if (found_book != NULL){

		if (found_book->getAuthor() != author || found_book->getTitle() != title)
			return false;

		found_book->increaseNum_of_copies();
		found_book->increaseNum_of_available_copies();
	}

	else{
		books.addBook(Book(title, author, ISBN));
	}
	return true;
}


/*
remove a single book  from the collection only if it is available.
*/
bool Library_Manager::removeBook(const long &ISBN){

	Book * found_book = books.findByISBN(ISBN);

	if (found_book == NULL || !found_book->isAvailable()) return false;

	found_book->decreaseNum_of_copies();
	found_book->decreaseNum_of_available_copies();

	//if we removed the last copy , delete book from collection!
	if (found_book->getNum_of_copies() == 0)
		return books.removeBook(*found_book);

	return false;
}


void Library_Manager::reportBooksStatus()		 	{

	list<Book*const > booksList = books.getAllBooks();
	list<Book*const >::const_iterator citer = booksList.cbegin();

	cout << "****************************[Books Report]*******************************";
	cout << endl
		<< setw(10) << "ISBN"
		<< setw(25) << "title"
		<< setw(13) << "author"
		<< setw(15) << "available"
		<< setw(10) << "total"
		<< setw(0) << endl;

	while (citer != booksList.cend()){
		cout << setw(10) << (*citer)->getISBN()
			<< setw(25) << (*citer)->getTitle()
			<< setw(13) << (*citer)->getAuthor()
			<< setw(15) << (*citer)->getNum_of_available_copies()
			<< setw(10) << (*citer)->getNum_of_copies()
			<< setw(0) << endl;

		citer++;
	}
	cout << "*************************************************************************";
	cout << endl << endl;
}


void Library_Manager::addBorrower(const std::string &name){
	borrowers.addBorrower(Borrower(name));
}

bool Library_Manager::removeBorrower(const long &id){
	Borrower *found_borrower = findBorrower_ById(id);
	return found_borrower == NULL ? false : borrowers.removeBorrower(*found_borrower);
}


void Library_Manager::reportOnAllBorrowers(){

	list <Borrower*const > allBorrowers = borrowers.getAllBorrowes();
	cout << "**************************[Borrowers Report]*****************************";
	cout << endl
		<< setw(7) << "ID"
		<< setw(25) << "name"
		<< setw(0) << endl;

	for (list <Borrower*const >::const_iterator iter = allBorrowers.begin(); iter != allBorrowers.end(); ++iter)
	{
		if ((*iter)->hasBooks())
		{
			cout << setw(7) << (*iter)->getId()
				<< setw(25) << (*iter)->getName()
				<< setw(0) << endl;
		}
	}
	cout << "*************************************************************************";
	cout << endl << endl;
}