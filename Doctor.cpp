#include "Doctor.h"

void Doctor::treatPatient(Patient patient, int time)
{
	if (busy) //If there is currently being a patient treated
	{
		if ((time - patient.getTreatmentTime()) > (patient.getTreatmentTime()))
		{
			hospital->recordVisit(patient, time);
			patient.setSeverity(0); //Patient is cured
		}
	}
	int time_needed = my_random.next_int(this->TreatmentTime);
	patient.setTreatment(time_needed);
}
