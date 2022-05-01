#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED
#include <iostream>
#include <string>
#include <cstdlib>
#include "linkedList.h"
#include "Customer.h"
using namespace std;


class CustomerList :public linkedListType<Customer>
{
	friend ostream& operator<<(ostream&, const CustomerList&);
public:
	void AddCustomer(Customer& customer);
	bool SearchCustomerByName(string) const;
	// void function to help Search Customer Name
	void voidForSearchName(string searchByName, bool found, nodeType<Customer>* &current) const;
	Customer getCustomerByName(string fname) const;
	void UpdateCustomer(Customer& current);
	void UpdateDataFile(ofstream& file);
};
#endif
