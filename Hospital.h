#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "Caregiver.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Random.h"

extern std::vector<Patient> citizens;
extern Random my_random;
class Hospital {
private:
	std::string _name;
	std::vector<Caregiver *> staff;
	double arrival_rate; //How often do new cases arrive?
	std::multimap<std::string, int> records; //Store records on patients name and severity of illness
	int num_served; //How many patients have come through the hospital?
	double avg_time; //How long was the average visit?
public:
	std::priority_queue<Patient> waiting_room;
	Hospital(std::string name);
	std::string getName();
	void triage(Patient &new_arrival);
	void setRate(double rate);
	void setStaff(int nurses, int doctors);
	void admitPatient(int clock);
	void checkArrivals(int clock);
	void recordVisit(Patient treated, int clock);
	int calc_time();
	void display_records();
	void search_records(std::string name);
	void check_patients(int clock);
	int getNum();
};
#endif // !HOSPITAL_H_
