#include "Simulation.h"

using namespace std;

int main()
{
	string fileName = "Lab5a.txt";

	Simulation event;

	cout << "Taco Fry drive-in" << endl;

	event.simulate(fileName);

	return 0;
}

