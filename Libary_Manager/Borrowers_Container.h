#include "Borrower.h"
#include<map>
#include<list>
#include <string>



class Borrowers_Container{

public:
	~Borrowers_Container(){ /*	should  be empty!!	*/ }
	Borrowers_Container(){}

	bool			addBorrower(const Borrower & borrower);
	bool 			removeBorrower(const Borrower & borrower){ return borrowers.erase(borrower.getId()) == 1; }

	Borrower*const 	findByID(const unsigned int id);

	std::list<Borrower*const>	findByName(const std::string name);
	std::list<Borrower*const>	getAllBorrowes();

private:
	std::map<unsigned int,Borrower> borrowers;
};

