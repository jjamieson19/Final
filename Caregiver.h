#ifndef CAREGIVER_H_
#define CAREGIVER_H_
#include "Patient.h"
#include "Hospital.h"

class Caregiver {
protected:
	int PriorityMax;
	int TreatmentTime;
	bool busy;
	Hospital* hospital; //Pointer to the hospital we're working with
public:
	Caregiver(int priority, int treatment, Hospital work);
	virtual void treatPatient(Patient patient, int time) = 0;
	bool checkStatus();
	void changeStatus();
	void setHospital(Hospital* here);
};
#endif // !CAREGIVER_H_
