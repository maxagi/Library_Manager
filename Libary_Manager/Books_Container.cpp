#include "Books_Container.h"
using namespace std;

typedef map<unsigned long, Book>::iterator			books_iter;
typedef map<unsigned long, Book>::const_iterator	books_citer;



bool Books_Container::addBook(Book  book){
	return (books.insert(std::pair<unsigned long, Book>(book.getISBN(), book))).second;
}

static std::list<Book*const > findBookByString(map<unsigned long, Book> &books_map, const string text, const string type){
	list<Book*const> results;
	books_iter iter = books_map.begin();

	while (iter != books_map.end())
	{

		if (type == "title"){
			if (iter->second.getTitle() == text)
				results.push_back(&iter->second);
		}

		if (type == "author"){
			if (iter->second.getAuthor() == text)
				results.push_back(&iter->second);
		}
		iter++;
	}
	return results;
}


Book* const   Books_Container::findByISBN(const unsigned long isbn)		 {
	books_iter iter = books.find(isbn);
	return iter == books.cend() ? 0 : &iter->second;
}


std::list<Book*const >	Books_Container::findByTitle(const std::string title) {
	return findBookByString(books, title, "title");
}


std::list<Book*const >	Books_Container::findByAuthor(const std::string author) {
	return findBookByString(books, author, "author");
}

std::list<const Book*const >	Books_Container::getAllBooks()const {
	std::list<const Book*const> result;

	for (books_citer iter = books.cbegin(); iter != books.cend(); ++iter) {
		result.push_back(&iter->second);
	}

	return result;
}