#ifndef CAREGIVER_H_
#define CAREGIVER_H_
#include "Patient.h"
class Caregiver {
protected:
	int PriorityMax;
	int TreatmentTime;
	bool busy;
public:
	Caregiver(int priority, int treatment);
	virtual void treatPatient(Patient patient, int time) = 0;
	bool checkStatus();
	void changeStatus();
};
#endif // !CAREGIVER_H_
