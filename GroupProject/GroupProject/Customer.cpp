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


