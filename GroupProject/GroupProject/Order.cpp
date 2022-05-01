#include "Order.h"

ostream& operator<<(ostream& out, const Order& order)
{
	out << fixed << showpoint << setprecision(2);
	out << "Title: " << setw(15) << order.bookTitle << endl;
	out << "Unit Price: $" << setw(15) << order.unitPrice << endl;
	out << "Number: " << setw(15) << order.number << endl;
}


Order::Order() 
{
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

bool Order::operator==(const Order& order) const 
{
	return (bookTitle == order.bookTitle &&
		unitPrice == order.unitPrice && 
		number == order.number);
}

bool Order::operator!=(const Order& order) const
{
	return (bookTitle != order.bookTitle || 
		unitPrice != order.unitPrice || 
		number != order.number);
}


