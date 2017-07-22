#ifndef NURSE_H_
#define NURSE_H_
#include "Caregiver.h"
#include "Random.h"
#include "Hospital.h"
extern Random my_random;

class Nurse : public Caregiver {
public:
	Nurse(Hospital* work) : Caregiver(10, 10, work) { hospital = work; };
	void treatPatient(int time);
};
#endif // !NURSE_H_

