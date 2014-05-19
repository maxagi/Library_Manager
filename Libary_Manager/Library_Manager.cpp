#include "Library_Manager.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
unsigned int Borrower::next_id = 1;

/*
TODO:
ask Yossi if we need to check if some one is waiting for
the book , and if yes , let him borrow it .
*/

int Library_Manager::borrowBook(const unsigned long &ISBN, const unsigned int &borrower_id){
	Borrower * bor = findBorrower_ById(borrower_id);
	Book * book = findBook_ByISBN(ISBN);

	if (book == NULL || bor == NULL) return -1;

	if (book->isAvailable()){

		//don't allow borrower to borrow same book more than once
		if (bor->hasBook(book)) return -1;
		bor->addToBorrowed(book);
		book->addBorrower(bor);
		book->decrease_available(1);
		return 0;
	}

	else{
		return book->addToWaitingList(bor);
	}

}
/*
updates the book parameter only if all copies of the book are available
*/
bool Library_Manager::updateBook(const long &ISBN, const std::string &str, int c){
	Book * found_book = books.findByISBN(ISBN);
	if (found_book == NULL || found_book->getNum_of_available_copies() != found_book->getNum_of_copies())
		return false;
	if (c == 0)
		found_book->setTitle(str);
	else if (c == 1)
		found_book->setAuthor(str);
	return true;
}



int Library_Manager::returnBook(const unsigned long &ISBN, const unsigned int &borrower_id){
	Borrower * bor = findBorrower_ById(borrower_id);
	Book * book = findBook_ByISBN(ISBN);

	if (book == NULL || bor == NULL) return -1;

	book->removeBorrower(bor);
	bor->removeFromBorrowed(book);

	if (book->hasWaiters()){
		Borrower * newBorrower = book->popFirstInWaitingList();
		newBorrower->addToBorrowed(book);
		book->addBorrower(newBorrower);
		return 0;
	}

	book->increase_available(1);
	return 0;
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
		Book b(title, author, ISBN);
		b.increaseNum_of_copies(howMany - 1);
		b.increase_available(howMany - 1);
		books.addBook(b);

	}
	return true;
}


/*
remove a single book from the collection only if it is available.
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


void Library_Manager::reportBooksStatus(const string& title_or_isbn, const string &byWhat) {
	list< Book*const > booksList;

	//populate booksList according to byWhat param
	if (byWhat == "isbn"){
		//convert string to long:
		char * pEnd;
		unsigned long isbn = std::strtol(title_or_isbn.c_str(), &pEnd, 10);

		//find book by isbn and add it to booksList
		Book* book = findBook_ByISBN(isbn);
		if (book == NULL) return;
		booksList.push_back(book);
	}

	else if (byWhat == "title"){
		booksList = findBook_ByTitle(title_or_isbn);
	}
	else return;

	//iterate over booksList and print each book's details:
	cout << "****************************[Books Report]*******************************" << endl;
	for (list< Book*const >::const_iterator book_citer = booksList.cbegin(); book_citer != booksList.cend();++book_citer)
	{
		cout << "-------------------------------------------------------------------------" << endl;
		(*book_citer)->print();

		//print all borrowers of that book:
		cout << "borrowers:" << endl;
		list<const Borrower*const > bookBorrowers = (*book_citer)->getBorrowers();
		for (list<const Borrower*const >::const_iterator bor_citer = bookBorrowers.cbegin(); bor_citer != bookBorrowers.cend(); ++bor_citer)
		{
			(*bor_citer)->print();
		}
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "*************************************************************************" << endl << endl;
}



bool Library_Manager::removeBorrower(const long &id){
	Borrower *found_borrower = findBorrower_ById(id);
	return found_borrower == NULL ? false : borrowers.removeBorrower(*found_borrower);
}


void Library_Manager::reportOnAllBorrowers(const string& id_or_name,const string &byWhat) {
	list < Borrower*const > allBorrowers;

	//populate allBorrowers according to byWhat param
	if (byWhat == "id"){
		//convert string to int :
		unsigned int id;
		istringstream ss(id_or_name);
		ss >> id;
		Borrower *b = findBorrower_ById(id);
		if (b == NULL) return;
		//add found borrower to allBorrowers
		allBorrowers.push_back(b);
	}

	else if (byWhat == "name"){
		allBorrowers = findBorrower_ByName(id_or_name);
	}
	else return;

	//iterate over allBorrowers and print each borrower's details:
	cout << "**************************[Borrowers Report]*****************************"<<endl<<endl;
	for (list < Borrower*const >::const_iterator bor_citer = allBorrowers.cbegin(); bor_citer != allBorrowers.cend(); ++bor_citer)
	{
		cout << "-------------------------------------------------------------------------" << endl;
		(*bor_citer)->print();

		//print borrower's borrowed books list :
		cout << "list borrowed books:" << endl<<endl;
		list <const Book*const > borrowedBooks = (*bor_citer)->getBorrowedBooks();
		for (list <const Book*const >::const_iterator book_citer = borrowedBooks.cbegin(); book_citer != borrowedBooks.cend(); ++book_citer){
			(*book_citer)->print();
		}
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout <<endl<< "*************************************************************************"<<endl<<endl;
}

bool Library_Manager::updateBorrowerName(const unsigned int ID, const std::string &str){

	Borrower* found_borrower = findBorrower_ById(ID);

	if (found_borrower == NULL) return false;

	found_borrower->setName(str);

	return true;
}
