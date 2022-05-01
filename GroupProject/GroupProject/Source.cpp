////////////////////////////////////////////////////////////////////
// Date: 5/1/2022 
// By: Brandon Biggs, David Utshudiema, and Fabian Rosas
// File: Source.cpp
// Purpose: File containing the main driver function. Also includes declaration and definitions of driver functions. 
////////////////////////////////////////////////////////////////////

#include "CustomerList.h"
#include "OrderList.h"
#include "Order.h"
#include "Customer.h"
#include <fstream>
#include <sstream>

//function prototypes
void LoadCustomers(ifstream&, CustomerList&);
int selectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDataFile(CustomerList&);

int main()
{
	CustomerList customers;
	ifstream inFile;

	cout << "Welcome to Wake Bookstore!";
	LoadCustomers(inFile, customers);
	if (customers.isEmptyList())
	{
		cout << "No previous customer orders have been placed!";
	}
	else
	{
		cout << "All customers and orders are loaded.";
	}

	int userChoice = 0;
	while (userChoice != 6)
	{
		userChoice = selectMenu();

		switch (userChoice)
		{
		case 1:
			while (userChoice != 'n')
			{
				PlaceOrder(customers);
				cout << "Place another order (y or n)? ";
				cin >> userChoice;
			}
			break;
		case 2:
			UpdateOrder(customers);
			break;
		case 3:
			CancelOrder(customers);
			break;
		case 4:
			PrintOrders(customers);
			break;
		case 5:
			CheckoutOrders(customers);
			break;
		}
	}

	cout << "Thanks for shopping at Wake Bookstore!";
}

void LoadCustomers(ifstream& inFile, CustomerList& outList) 
{
	inFile.open("Book.txt");

	/////////////////////////////////
	// Declare all local variables //
	/////////////////////////////////
	int i = -1;
	int bookNumber;

	string line;
	string name, address, email, bookTitle;

	double bookUnitPrice;

	Order order;
	OrderList bookOrders;

	Customer customer;


	/////////////////////////////////
	//    Actual file read loop    //
	/////////////////////////////////
	while (getline(inFile, line))
	{
		if (line.at(0) == '%')
		{
			if (!bookOrders.isEmptyList())
			{
				customer = Customer(name, address, email, bookOrders);
				outList.AddCustomer(customer);
				bookOrders.destroyList();
			}

			name = line;
			i = -1;
			continue;
		}

		switch (++i)
		{
		case 0:
			address = line;
			break;
		case 1:
			email = line;
			break;
		case 2:
			bookTitle = line;
			break;
		case 3:
			bookUnitPrice = stod(line);
			break;
		case 4:
			bookNumber = stoi(line);

			// The last parameter for a book order is
			// the number of books
			order = Order(bookTitle, bookUnitPrice, bookNumber);
			bookOrders.AddOrder(order);

			// but there can be more book orders, so 
			// we partially reset the index (i).
			i = 1;
			break;
		default:
			// Help!!! This should theoretically never 
			// be reached!
			break;
		}

		line;
	}


	inFile.close();
}

int selectMenu() 
{
	string userInput;

	cout << "Please select one of the following actions: " << endl;
	cout << "1. Place an order." << endl
		<< "2. Update an order." << endl
		<< "3. Cancel an order." << endl
		<< "4. Print all orders." << endl
		<< "5. Checkout orders." << endl;
	cin >> userInput;
	return stoi(userInput);
}

void PlaceOrder(CustomerList& List)
{
	string userInput, name, title;
	double unitPrice;
	int number;
	Customer c;

	cout << "Enter Customer Name: " << endl;
	cin >> userInput;
	name = userInput;

	if (!List.SearchCustomerByName(userInput))
	{
		string address, email;

		cout << "New Customer." << endl;
		cout << "Enter customer address: " << endl;
		cin >> address;
		cout << "Enter customer email: " << endl;
		cin >> email;

		c = Customer(name, address, email, OrderList());
		List.AddCustomer(c);
	}
	else
	{
		c = List.getCustomerByName(name);
		cout << "Existing Customer." << endl;
	}

	cout << "Enter the book title: ";
	cin >> title;
	cout << endl << "Enter the price of the book: ";
	cin >> userInput;
	unitPrice = stod(userInput);
	cout << endl << "Enter the number of books: ";
	cin >> userInput;
	number = stoi(userInput);

	c.AddOrder(Order(title, unitPrice, number));
	cout << "New order is added for customer " << name << "." << endl << endl;
	UpdateDataFile(List);
}

void UpdateOrder(CustomerList& List)
{
	string userInput, title;
	cout << "Enter Customer Name: ";
	cin >> userInput;

	if (!List.SearchCustomerByName(userInput))
	{
		cout << endl << "Customer does not exist." << endl;
		return;
	}

	Customer c = List.getCustomerByName(userInput);
	cout << endl << "Enter the book title to be updated: ";
	cin >> title;

	cout << endl << "Enter the number of books to be updated: ";
	cin >> userInput;

	c.UpdateOrders(title, stoi(userInput));
	UpdateDataFile(List);
}

void CancelOrder(CustomerList& List)
{
	string name, title;
	cout << "Enter customer name: ";
	cin >> name;

	if (!List.SearchCustomerByName(name))
	{
		cout << "Customer does not exist." << endl;
		return;
	}

	Customer c;
	c = List.getCustomerByName(name);

	cout << "Enter book title: ";
	cin >> title;

	bool titleExists = false;
	for (Order o : c.getOrders())
	{
		if (o.checkTitle(title))
		{
			titleExists = true;
			break;
		}
	}

	if (!titleExists)
	{
		cout << "Book title does not exist." << endl;
		return;
	}

	List.getCustomerByName(name).CancelOrder(title);
	UpdateDataFile(List);
}

void PrintOrders(CustomerList& List)
{
	List.print();
}

void CheckoutOrders(CustomerList& List)
{
	string name;
	cout << "Enter customer name: ";
	cin >> name;

	if (!List.SearchCustomerByName(name))
	{
		cout << "Customer does not exist." << endl;
		return;
	}

	Customer c = List.getCustomerByName(name);
	c.checkoutOrders();
}

void UpdateDataFile(CustomerList& List)
{
	ofstream outFile;
	outFile.open("BookOrders.txt");

	for (Customer c : List)
	{
		outFile << "%" << c.getCustomerName() << endl
			<< c.getAddress() << endl
			<< c.getEmail() << endl;

		for (Order o : c.getOrders())
		{
			outFile << o.getTitle() << endl
				<< o.getPrice() << endl
				<< o.getNumber() << endl;
		}
	}

	outFile.close();
}
