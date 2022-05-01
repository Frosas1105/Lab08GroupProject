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
