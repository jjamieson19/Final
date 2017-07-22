#include "Caregiver.h"

Caregiver::Caregiver(int priority, int treatment, Hospital* here)
{
	PriorityMax = priority;
	TreatmentTime = treatment;
	busy = false;
	hospital = here;
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

bool Caregiver::capable(Patient new_patient)
{
	if (new_patient.getSeverity() <= PriorityMax)
		return true;
	else
		return false;
}

void Caregiver::set_care(Patient new_patient)
{
	in_care = new_patient;
}

Patient Caregiver::getCare()
{
	return in_care;
}
