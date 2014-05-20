#ifndef	 BORROWERS_CONTAINER_H
#define	 BORROWERS_CONTAINER_H

#include "Borrower.h"
#include<map>
#include<list>
#include <string>



class Borrowers_Container{

public:
	~Borrowers_Container(){}
	Borrowers_Container(){}

	bool							addBorrower(const Borrower & borrower);
	bool 							removeBorrower(const Borrower & borrower){ return borrowers.erase(borrower.getId()) == 1; }

	Borrower*const 					findByID(const unsigned int id);
	const Borrower*const 			findByID(const unsigned int id)const ;

	std::list<Borrower*const>		findByName(const std::string name);
	std::list<const Borrower*const>	findByName(const std::string name)const;

	std::list<const Borrower*const>	getAllBorrowes()const ;

private:

	Borrowers_Container(const Borrowers_Container & other);
	Borrowers_Container & operator=(const Borrowers_Container & other);


	std::map<unsigned int,Borrower> borrowers;
};
#endif
