#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Caregiver.h"

class Doctor :public Caregiver {
public:
	Doctor() : Caregiver(20, 20) {};
	void treatPatient(Patient patient, int time);
};
#endif // !DOCTOR_H_