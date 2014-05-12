
#include<list>

class Book;

class Books_Container{

public:
	~Books_Container();
	Books_Container();

	void addBook(const Book & book);
	void removeBook(const Book & book);

	/*
	more functions
	*/

private:
	std::list<Book> books;
};