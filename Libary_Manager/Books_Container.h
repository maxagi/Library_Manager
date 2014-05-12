
#include<map>

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
	std::map<Book,unsigned long> books; // book-->ISBN
};