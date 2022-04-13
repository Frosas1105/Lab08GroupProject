#include "Order.h"

Order::Order() {
	bookTitle = "";
	unitPrice = 0.0;
	number = 0;
}

Order::Order(string bt, double up, int num)
{
	bookTitle = bt;
	unitPrice = up;
	number = num;
}

bool Order::checkTitle(string name)
{
	return bookTitle == name;
}

double Order::CalculateCost()
{
	double totalCost = 0.0;
	totalCost = unitPrice * number;
	return totalCost;
}

void Order::setNumber(int)
{
	number = number;
}

string Order::getTitle()
{
	return bookTitle;
}

double Order::getPrice()
{
	return unitPrice;
}

int Order::getNumber()
{
	return number;
}

bool Order::operator==(const Order& orderTwo) const 
{
	if (bookTitle == orderTwo.bookTitle &&
		unitPrice == orderTwo.unitPrice)
		return true;
	else
	{
		return false;
	}
}

bool Order::operator!=(const Order& orderTwo) const
{
	if (bookTitle != orderTwo.bookTitle &&
		unitPrice != orderTwo.unitPrice)
		return true;
	else
	{
		return false;
	}
}


