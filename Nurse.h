#ifndef NURSE_H_
#define NURSE_H_
#include "Caregiver.h"
#include "Hospital.h"

class Nurse : public virtual Caregiver {
public:
	Nurse(Hospital* work) : Caregiver(10, 10, work) {}
	void treatPatient(Patient patient, int time);
};
#endif // !NURSE_H_

