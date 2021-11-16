#include "Inventory.h"
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	LinkedSortedList<Inventory>* store = new LinkedSortedList<Inventory>();

	string filename;
	cout << "Enter file name : ";
	cin >> filename;
	
	ifstream file(filename);
	string entry;
	while (file.peek() != EOF)
	{
		while (getline(file, entry))
		{
			int amount = 0;
			double perUnitCost = 0.0;
			string name;
			string spaceDelimiter = " ";

			if (!entry.empty())
			{
				amount = stoi(entry.substr(0, entry.find(spaceDelimiter)));
				string subbedString = entry.substr(entry.find(spaceDelimiter)+1);
				perUnitCost = stod(subbedString.substr(0, subbedString.find(spaceDelimiter)));
				name = subbedString.substr(subbedString.find(spaceDelimiter) + 1);
				Inventory product(amount, perUnitCost, name);
				store->insertSorted(product);
			} 
		}
	}
	cout << endl;
	cout << "Mustang Sally's electronics store" << endl;
	cout << endl;
	cout << left << setw(20) << "Product" << setw(20) << "Cost per " << setw(20) << "Quantity " << setw(20) << "Value on hand " << endl;
	cout << endl;

	double totalValue = 0.0;
	double productTotalValue = 0.0;
	int position = 1;
	while (!store->isEmpty() && position <= store->getLength())
	{
		Inventory selection = store->getEntry(position);
		store->removeSorted(selection);
		productTotalValue = selection.value();
		totalValue += productTotalValue;
		cout << left << setw(20) << selection.getProductName() << "$" << setw(20) << selection.getPricePer()
			<< setw(20) << selection.getQuantity() << "$ " << right << setw(6) << productTotalValue << endl;

		position++;
	}
	cout << right << setw(69) << "---------" << endl;
	cout << left << setw(60) << "Total value = " << " $" << right << setw(7) << totalValue << endl;

	return 0;
}
