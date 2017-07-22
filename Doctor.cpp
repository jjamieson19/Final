#include "Doctor.h"

void Doctor::treatPatient(int time)
{
	if (busy) //If there is currently being a patient treated
	{
		if ((time - in_care.getTreatmentTime()) > (in_care.getTreatmentTime()))
		{
			hospital->recordVisit(in_care, time);
			this->set_care(Patient());
			changeStatus(); //Caregiver is open
			if (this->checkStatus() == true)
				std::cout << "Failure to change" << std::endl;
		}
	}
	if (!busy) //If there is no patient currently
	{
		int time_needed = my_random.next_int(this->TreatmentTime);
		in_care.setTreatment(time_needed);
		this->changeStatus(); //Caregiver is now busy with patient
	}
	
}
