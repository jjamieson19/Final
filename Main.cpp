//JD Jamieson
//CS273
//Final Project Simulation
#include "Simulator.h"
using namespace std;
int main() {
	Simulator hospital;
	hospital.collectData();
	hospital.runSimulation();
	hospital.showStats();
}