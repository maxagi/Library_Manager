
#include<list>

class Borrower;

class Borrowers_Container{

public:
	~Borrowers_Container();
	Borrowers_Container();

	void addBorrower(const Borrower & b);
	void removeBorrower(const Borrower & b);

	/*
	more functions
	*/

private:
	std::list<Borrower> borrowers;
};

