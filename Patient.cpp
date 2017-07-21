#include "Patient.h"

Patient::Patient(std::string name)
{
	_name = name;
}

int Patient::getArrival()
{
	return arrival_time;
}

std::string Patient::getName()
{
	return _name;
}

int Patient::getSeverity()
{
	return severity;
}

int Patient::getTreatmentTime()
{
	return treatment_time;
}

void Patient::setSeverity(int prio)
{
	severity = prio;
}

bool Patient::operator<(const Patient &other) const
{
	if (severity<other.severity)
		return true;
	else
		return false;
}

void Patient::setTime(int time)
{
	arrival_time = time;
}

void Patient::setTreatment(int length)
{
	treatment_time = length;
}
