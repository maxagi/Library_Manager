#include "Library_Manager.h"

unsigned int Borrower::next_id = 1;

bool Library_Manager::addBook(const std::string title, const std::string author, const long ISBN){

	Book b(title, author, ISBN);
	return books.addBook(b);
}
