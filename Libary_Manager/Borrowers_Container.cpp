#include "Borrowers_Container.h"
#include<assert.h>

using namespace std;

typedef std::map<unsigned int, Borrower>::iterator borrowers_iter;
typedef std::map<unsigned int, Borrower>::const_iterator borrowers_citer;

Borrower*const 	Borrowers_Container::findByID(const unsigned int id){
	borrowers_iter iter = borrowers.find(id);
	return iter == borrowers.cend() ? 0 : &iter->second;
}
const Borrower*const 	Borrowers_Container::findByID(const unsigned int id)const {
	borrowers_citer iter = borrowers.find(id);
	return iter == borrowers.cend() ? 0 : &iter->second;
}


//fills lst or const_lst  (depending on which is null) with all borrowers with specified name 
static void findByName_helper(const std::map<unsigned int, Borrower>& borrowers, const std::string name, 
	list<Borrower*const> *const lst, list<const Borrower*const> *const const_lst){

	borrowers_citer iter = borrowers.cbegin();

	while (iter != borrowers.cend())
	{
		if (iter->second.getName() == name)
		{
			const_lst == NULL ? lst->push_back(const_cast<Borrower*>(&iter->second)) : const_lst->push_back(&iter->second);
		}
		iter++;
	}
}


list<Borrower*const>	Borrowers_Container::findByName(const std::string name){
	list<Borrower*const> results;
	findByName_helper(borrowers,name, &results, NULL);
	return results;
}

list<const Borrower*const>	Borrowers_Container::findByName(const std::string name)const{
	list<const Borrower*const> results;
	findByName_helper(borrowers,name, NULL,&results);
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