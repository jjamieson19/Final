#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Caregiver.h"
#include "Random.h"
#include "Hospital.h"
extern Random my_random;

class Doctor : public Caregiver{
public:
	Doctor(Hospital* work) : Caregiver(20, 20, work) {};
	void treatPatient(int time);
};

#endif // !DOCTOR_H_