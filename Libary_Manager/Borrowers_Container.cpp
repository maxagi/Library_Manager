#include "Borrowers_Container.h"
#include<assert.h>

using namespace std;

typedef std::map<unsigned int, Borrower>::iterator borrowers_iter;
typedef std::map<unsigned int, Borrower>::const_iterator borrowers_citer;

Borrower*const 	Borrowers_Container::findByID(const unsigned int id){
	borrowers_iter iter = borrowers.find(id);
	return iter == borrowers.cend() ? 0 : &iter->second;
}

list<Borrower*const>	Borrowers_Container::findByName(const std::string name){
	list<Borrower*const> results;
	borrowers_iter iter = borrowers.begin();
	
	while (iter != borrowers.end())
	{
		if (iter->second.getName() == name)
		{
			results.push_back(&iter->second);
		}
		iter++;
	}
	return results;
}


bool Borrowers_Container::addBorrower(const Borrower & borrower){
	return (borrowers.insert(pair<unsigned int, Borrower>(borrower.getId(), borrower))).second;
}


std::list<const Borrower*const>	Borrowers_Container::getAllBorrowes()const {
	std::list<const Borrower*const> result;

	for (borrowers_citer citer = borrowers.cbegin(); citer != borrowers.cend(); ++citer) {
		result.push_back(&citer->second);
	}

	return result;
}