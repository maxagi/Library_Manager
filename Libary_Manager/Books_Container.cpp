#include "Books_Container.h"
using namespace std;

typedef map<unsigned long, Book>::iterator			books_iter;
typedef map<unsigned long, Book>::const_iterator	books_citer;



bool Books_Container::addBook(const Book book){
	return (books.insert(std::pair<unsigned long, Book>(book.getISBN(), book))).second;
}

//fills lst or const_lst  (depending on which is null) with all books that their param matches text
static void findBookByString(const std::map<unsigned long, Book> &books ,const std::string text, const std::string param,
	std::list< Book*const > *const lst, std::list<const Book*const > *const const_lst){

	books_citer iter = books.begin();
	while (iter != books.cend())
	{

		if (param == "title"){
			if (iter->second.getTitle() == text)
				lst == NULL ? const_lst->push_back(&iter->second) : lst->push_back(const_cast<Book*>(&iter->second));
		}

		if (param == "author"){
			if (iter->second.getAuthor() == text)
				lst == NULL ? const_lst->push_back(&iter->second) : lst->push_back(const_cast<Book*>(&iter->second));
		}
		iter++;
	}
}


Book* const Books_Container::findByISBN(const unsigned long isbn)	{
	books_iter iter = books.find(isbn);
	return iter == books.end() ? 0 : &iter->second;
}
const Book* const Books_Container::findByISBN(const unsigned long isbn)const	{
	books_citer iter = books.find(isbn);
	return iter == books.cend() ? 0 : &iter->second;
}




std::list< Book*const >	Books_Container::findByTitle(const std::string title) {
	std::list< Book*const > tmp;
	findBookByString(books,title, "title", &tmp,NULL);
	return tmp;
}
std::list<const Book*const >	Books_Container::findByTitle(const std::string title)const {
	std::list<const Book*const > tmp;
	findBookByString(books,title, "title", NULL,&tmp);
	return tmp;
}




std::list< Book*const >	Books_Container::findByAuthor(const std::string author) {
	std::list< Book*const > tmp;
	 findBookByString(books,author, "author",&tmp,NULL);
	 return tmp;
}
std::list<const Book*const >	Books_Container::findByAuthor(const std::string author)const {
	std::list<const Book*const > tmp;
	findBookByString(books,author, "author", NULL,&tmp);
	return tmp;
}



std::list<const Book*const >	Books_Container::getAllBooks()const {
	std::list<const Book*const> result;

	for (books_citer iter = books.cbegin(); iter != books.cend(); ++iter) {
		result.push_back(&iter->second);
	}

	return result;
}