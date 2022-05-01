////////////////////////////////////////////////////////////////////
// Date: 5/01/2022
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: Order.h
// Purpose: Declaring all data members and member functions for the class Order.
////////////////////////////////////////////////////////////////////
#pragma once
#pragma once
#include "linkedList.h"
using namespace std;

class Order
{
	friend ostream& operator<<(ostream&, const Order&);
private:
	string bookTitle;
	double unitPrice;
	int number;
public:
	Order();
	Order(string, double, int);
	bool checkTitle(string name);
	double CalculateCost();
	void setNumber(int number);
	string getTitle();
	double getPrice();
	int getNumber();
	bool operator==(const Order&) const;
	bool operator!=(const Order&) const;
};

