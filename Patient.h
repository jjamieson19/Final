#ifndef PATIENT_H_
#define PATIENT_H_
#include <string>

class Patient {
private:
	std::string _name;
	int arrival_time; //When did they arrive at the ER?
	int severity; //How sick are they? Assigned through Hospital.triage()
	int treatment_time; //How long will treating this person take?
public:
	Patient(std::string name);
	int getArrival();
	std::string getName();
	int getSeverity();
	int getTreatmentTime();
	bool operator<(const Patient &other) const;
	void setSeverity(int prio);
	void setTime(int clock);
	void setTreatment(int length);
	
};
#endif // !PATIENT_H_
