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
	void setNumber(int);
	string getTitle();
	double getPrice();
	bool operator==(const Order&) const;
	bool operator!=(const Order&) const;
};

