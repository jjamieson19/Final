#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Caregiver.h"
#include "Hospital.h"

class Doctor : public virtual Caregiver{
public:
	Doctor(Hospital* work) : Caregiver(20, 20, work) {}
	void treatPatient(Patient patient, int time);
};

#endif // !DOCTOR_H_