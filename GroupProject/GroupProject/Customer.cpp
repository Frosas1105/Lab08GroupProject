////////////////////////////////////////////////////////////////////
// Date: 5/1/2022 
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: Customer.cpp
// Purpose: File containing the function definitions for the Customer Class. 
////////////////////////////////////////////////////////////////////
#include "Customer.h"

ostream& operator<<(ostream& out, const Customer& customer)
{

}

Customer::Customer() 
{
	name = "";
	address = "";
	email = "";
	orders = OrderList();
}

Customer::Customer(string nm, string ad, string em, OrderList ord)
{
	name = nm;
	address = ad;
	email = em;
	orders = ord;
}

OrderList Customer::getOrders()
{
	return orders;
}

void Customer::AddOrder(Order newOrder)
{
	orders.AddOrder(newOrder);
}

void Customer::UpdateOrders(string title, int number)
{
	orders.UpdateOrder(title, number);
}

string Customer::getCustomerName()
{
	return name;
}

string Customer::getAddress()
{
	return address;
}

string Customer::getEmail()
{
	return email;
}

double Customer::checkoutOrders()
{
	double total;
	return total = orders.CalculateSubtotal();
}

bool Customer::operator==(const Customer& customer) const
{
	return (name == customer.name && address == customer.address
		&& email == customer.email);
}

bool Customer::operator!=(const Customer& customer) const
{
	return (name != customer.name || address != customer.address
		|| email != customer.email);
}
