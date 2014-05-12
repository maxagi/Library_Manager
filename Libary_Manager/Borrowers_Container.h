
#include<list>

class Borrower;

class Borrowers_Container{

public:
	~Borrowers_Container(){ /*	should NOT be empty!!	*/ }
	Borrowers_Container(){}

	void addBorrower(const Borrower & b);
	void removeBorrower(const Borrower & b);

	/*
	more functions
	*/

private:
	std::list<Borrower> borrowers;
};

