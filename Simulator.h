#ifndef SIMULATE_H_
#define SIMULATE_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include <fstream>
#include "Hospital.h"
#include "Random.h"
using namespace std;
Random my_random;
vector<Patient> citizens; //Every citizen is a potential patient

class Simulator {
private:
	int clock; //current time in simulation
	int total_time= 10080; //Total time for simulation
	Hospital* hospital; //The hospital we are working with
public:
	Simulator() {
		hospital = new Hospital("273ville");
		ifstream fname;
		fname.open("..\\FirstName.txt");
		if (fname.fail()) {
			cout << "Failure to upload FirstName." << endl;
		}
		ifstream lname;
		lname.open("..\\LastName.txt");
		if (lname.fail()) {
			cout << "Failure to upload LastName." << endl;
		}
		for (int i = 0; i < 2000; i++) //Begin creating the denizens of the town
		{
			if (lname.eof()) //Check if last name file has reached the end
			{
				lname.clear();
				lname.seekg(0, ios::beg); //Reset last name file to beginning and continue
			}
			string first_name, last_name;
			getline(fname, first_name);
			getline(lname, last_name);
			citizens.push_back((Patient(first_name + " " + last_name)));
		}
		fname.close();
		lname.close();
	}
	
	void collectData() { //Allow the user to input necessary values
		cout << "Welcome to the " << hospital->getName() << " emergency room." << endl;
		
		cout << "How many nurses are working in the ER?";
		int nurse_num;
		cin >> nurse_num;
		cout << "How many doctors are working in the ER?";
		int doc_num;
		cin >> doc_num;
		hospital->setStaff(nurse_num, doc_num);
		cout << "What is the average arrival rate of patients per hour?";
		double rate;
		cin >> rate;
		hospital->setRate(rate / 60);
	}
	void runSimulation() {
		srand(time(NULL));
		for (clock = 0; clock < total_time; ++clock)
		{
			hospital->checkArrivals(clock);
		}
	}
	void showStats() {
		cout << "Average visit time: " << hospital->calc_time() << endl;
		cout << "Number of visitors" << hospital->getNum() << endl;
		cout << endl;
		cout << "Press 1 to display visitors to hospital" << endl;
		cout << "Press 2 to search for specific patients" << endl;
		cout << "Press 3 to exit" << endl;
		int resp;
		cin >> resp;
		while (resp != 3) {
			if (resp == 1) {
				hospital->display_records();
				cin >> resp;
			}

			else if (resp == 2) {
				cin.ignore();
				cout << "Search for: ";
				string search;
				getline(cin, search);
				hospital->search_records(search);
				
			}
			else
				resp = 3; //Any invalid input will exit the program
		}
	}
};
#endif