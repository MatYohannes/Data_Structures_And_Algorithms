#include "Simulation.h"

using namespace std;

int main()
{
	// Input simulationTest filename below
	string fileName = "SimulationTest1.txt";

	Simulation event;

	cout << "Taco Fry drive-in" << endl;

	event.simulate(fileName);

	return 0;
}

