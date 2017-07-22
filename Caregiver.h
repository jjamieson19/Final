#ifndef CAREGIVER_H_
#define CAREGIVER_H_
#include "Patient.h"
class Hospital;
class Caregiver {
protected:
	
	int PriorityMax;
	int TreatmentTime;
	bool busy;
	Hospital* hospital; //Pointer to the hospital we're working with
	Patient in_care; //Who are you caring for?
public:
	Caregiver(int priority, int treatment, Hospital* here);
	virtual void treatPatient(int time) = 0;
	bool checkStatus();
	void changeStatus();
	void setHospital(Hospital *here);
	bool capable(Patient new_patient);
	void set_care(Patient new_patient);
	Patient getCare();
};

#endif // !CAREGIVER_H_
