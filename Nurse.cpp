#include "Nurse.h"

void Nurse::treatPatient(Patient patient, int time)
{
	if (busy) //If there is currently being a patient treated
	{
		if ((time - patient.getTreatmentTime()) > (patient.getTreatmentTime()))
		{

		}
	}
		int time_needed = my_random.next_int(this->TreatmentTime);
		patient.setTreatment(time_needed);
}
