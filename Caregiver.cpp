#include "Caregiver.h"

Caregiver::Caregiver(int priority, int treatment)
{
	PriorityMax = priority;
	TreatmentTime = treatment;
	busy = false;
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
