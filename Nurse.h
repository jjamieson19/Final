#ifndef NURSE_H_
#define NURSE_H_
#include "Caregiver.h"
#include "Hospital.h"
class Nurse :public Caregiver {
public:
	Nurse() :Caregiver(10, 10) {};
	void treatPatient(Patient patient, int time);
};
#endif // !NURSE_H_

