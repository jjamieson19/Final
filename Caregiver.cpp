#include "Caregiver.h"

Caregiver::Caregiver(int priority, int treatment, Hospital work)
{
	PriorityMax = priority;
	TreatmentTime = treatment;
	busy = false;
	hospital = &work;
}

bool Caregiver::checkStatus()
{
	return busy;
}

void Caregiver::changeStatus()
{
	if (busy == true)
		busy = false;
	else
		busy = true;
}

void Caregiver::setHospital(Hospital * here)
{
	hospital = here;
}
