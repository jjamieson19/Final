//JD Jamieson
//CS273
//Final Project Simulation
#include "Simulator.h"
using namespace std;
int main() {
	srand(time(NULL));
	Simulator hospital;
	hospital.collectData();
	hospital.runSimulation();
	hospital.showStats();
	return 0;
}