#include "Inventory.h"

// Constructor for class with three parameters
// @ param : q is the quantity, pp is the price per unit, and pn is the products name
// @ post : constructs Inventory with quantity = q, pricePer = pp, and productName = pn
Inventory::Inventory(int q, double pp, string pn) : quantity(q), pricePer(pp), productName(pn)
{
}

// Getters
int Inventory::getQuantity() const
{
	return quantity;
}
double Inventory::getPricePer() const
{
	return pricePer;
}
string Inventory::getProductName() const
{
	return productName;
}

// Returns the value of the ( pricePer * quantity )
double Inventory::value() {
	return getPricePer() * getQuantity();
}

// Overload Operators
// Operators needed for comparing and sorting object Inventory in LinkedSortedList
// LinkedSortedList is sorted by productName
bool Inventory::operator == (const Inventory& right)
{
	if (productName.compare(right.getProductName()))
	{
		return true;
	}
	return false;
}
bool Inventory::operator > (const Inventory& right)
{
	if (productName > right.getProductName())
	{
		return true;
	}
	return false;
}
bool Inventory::operator != (const Inventory& right)
{
	if (productName != right.getProductName())
	{
		return true;
	}
	return false;
}