#ifndef OrderList_H
#define OrderList_H
#pragma once
#include <iostream>
#include <cstdbool>
#include <fstream>
#include "linkedList.h"
#include "Order.h"

class OrderList :public linkedListType<Order>
{
	friend ostream& operator<<(ostream&, const OrderList&);
public:
	void AddOrder(Order&);
	void UpdateOrder(string, int);
	void CancelOrder(string);
	double CalculateSubtotal();
	void UpdateDateFile(ofstream&);

private:
	void SearchOrderList(string title, bool& found, nodeType<Order>*& current) const;
};
#endif


