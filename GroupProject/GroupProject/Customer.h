////////////////////////////////////////////////////////////////////
// Date: 5/01/2022
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: Customer.h
// Purpose: Declaring all data members and member functions for the class Customer.
////////////////////////////////////////////////////////////////////
#pragma once
#include "OrderList.h"

class Customer
{
	friend ostream& operator<<(ostream&, const Customer&);
private:
	string name;
	string address;
	string email;
	OrderList orders;
public:
	Customer();
	Customer(string, string, string, OrderList);
	OrderList getOrders();
	void AddOrder(Order);
	void UpdateOrders(string, int);
	void CancelOrder(string);
	string getCustomerName();
	string getAddress();
	string getEmail();
	double checkoutOrders();
	bool operator==(const Customer&) const;
	bool operator!=(const Customer&) const;
};

