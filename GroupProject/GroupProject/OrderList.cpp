////////////////////////////////////////////////////////////////////
// Date: 5/1/2022 
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: OrderList.cpp
// Purpose: File containing the function definitions for the OrderList Class. 
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "linkedList.h"
#include "Order.h"
#include "OrderList.h"

using namespace std;

ostream& operator<<(ostream& out, const OrderList& orders) {
    orders.print();
        return out;

}

void OrderList::AddOrder(Order& order)    {
    insertLast(order);

}
void OrderList::UpdateOrder(string title , int number)    {
    bool found = false;
        nodeType<Order>* location;

        
        SearchOrderList(title, found, location);

        if (found) {
                location->info.setNumber(number);
                cout << "The order is updated." << endl;
        } else {
                cout << "Order is not found." << endl;
        }
        return;


}
void OrderList::CancelOrder(string) {
    bool found = false;
        nodeType<Order>* current = first;
        SearchOrderList(title, found, current);
        deleteNode(current->info);

}
double OrderList::CalculateSubtotal()   {
    nodeType<Order>* current;
        current = first;
        double subtotal = 0.0;
        while (current != nullptr) {
                subtotal += (current->info.CalculateCost());
                current = current->link;
        }
        return subtotal;

}
void OrderList::UpdateDataFile(ofstream&)   {
    nodeType<Order>* current;
        current = first;
        while (current != nullptr) {
                file << current->info.getTitle() << endl;
                file << current->info.getPrice() << endl;
                file << current->info.getNumber() << endl;
                current = current->link;
        }
        return;

}
void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const {
    found = false;
        current = first;
        

        while (current != nullptr && !found) {
                if (current->info.checkTitle(title)) {
                        found = true;
                } else {
                        current = current->link;
                }
        }
        return;
    
}
