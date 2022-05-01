#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdbool>
#include "CustomerList.h"

using namespace std;

ostream& operator<<(ostream& os, const CustomerList& customer)  {
    customer.print();
	return (os);

}

void CustomerList::AddCustomer(Customer& customer)   {
    insertLast(customer);

}

bool CustomerList::SearchCustomerByName(string searchByName, bool found) const {
    bool found = false;
	nodeType<Customer> *location;
    voidForSearchName(searchByName, found, location);

	return (found);

}

void CustomerList::voidForSearchName(string searchByName, bool found, nodeType<Customer>* &current) const{
    found = false;
	current = first;

	while (current != nullptr && !found) {
		if (current->info.checkCustomerName(searchByName)) {
			found = true;
		} else {
			current = current->link;
		}
	}
    }
Customer getCustomerByName(string fname)  {
    Customer z;
    return z;
    
}
void CustomerList::UpdateCustomer(Customer&){
    bool found = false;
	nodeType<Customer> *location;

    voidForSearchName(current.getCustomerName(), found, location);

	if (found) {
		location->info.getCustomerName();
		cout << "The customer is updated." << endl;
	} else {
		cout << "The customer is not found." << endl;
	}
	return;

}
void CustomerList::UpdateDataFile(ofstream& file)    {
    nodeType<Customer> *current = first;

	while (current != nullptr) {
		file << current->info.getCustomerName() << endl
		     << current->info.getAddress() << endl
		     << current->info.getEmail() << endl;
		current = current->link;
	}
	return;

}