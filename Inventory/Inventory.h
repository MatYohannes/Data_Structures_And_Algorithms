#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include "LinkedSortedList.h"

using namespace std;

// Class that holds the quantity, price per unit and the products names
class Inventory
{
private:
	int quantity; // the amount of the inventory product
	double pricePer; // the price per unit of the inventory product
	string productName; // the name of the inventory product

public:
	// Constructor

	// Constructor for class with three parameters
	// @ param : q is the quantity, pp is the price per unit, and pn is the products name
	// @ post : constructs Inventory with quantity = q, pricePer = pp, and productName = pn
	Inventory(int q, double pp, string pn);

	// Getter
	int getQuantity() const; // Gets quantity
	double getPricePer() const; // Gets pricePer
	string getProductName() const; // Gets productName

	double value(); // Returns the value of the ( pricePer * quantity )
	
	// Overload Operators
	// Operators needed for comparing and sorting object Inventory in LinkedSortedList
	// LinkedSortedList is sorted by productName
	bool operator == (const Inventory& right);
	bool operator > (const Inventory& right);
	bool operator != (const Inventory& right);

}; // end Inventory
#endif // !INVENTORY_H

