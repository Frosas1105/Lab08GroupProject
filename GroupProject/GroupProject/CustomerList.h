////////////////////////////////////////////////////////////////////
// Date: 5/01/2022
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: CustomerList.h
// Purpose: Declaring all data members and member functions for the class CustomerList.
////////////////////////////////////////////////////////////////////
#pragma once
#include "Customer.h"

class CustomerList :public linkedListType<Customer>
{
	friend ostream& operator<<(ostream&, const CustomerList&);
public:
	void AddCustomer(Customer&);
	bool SearchCustomerByName(string) const;
	Customer getCustomerByName(string) const;
	void UpdateCustomer(Customer&);
	void UpdateDataFile(ofstream&);
};

