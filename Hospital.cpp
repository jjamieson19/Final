#include "Hospital.h"

Hospital::Hospital(std::string name)
{
	_name = name;
	num_served = 0;
	avg_time = 0;
}

std::string Hospital::getName()
{
	return _name;
}

void Hospital::triage(Patient &new_arrival)
{
	int chance = my_random.next_int(10); 
	if (chance <= 6) 
	{
		new_arrival.setSeverity((rand() % 10) + 1); //Priorities 1-10 occur 70% of the time
	}
	else if (chance == 7 || chance == 8)
		new_arrival.setSeverity((rand() % 5) + 11); //Priorities 11-15 occur 20% of the time
	else
		new_arrival.setSeverity((rand() % 5) + 16); //Priorities 16-20 occur 10% of the time
	waiting_room.push(new_arrival);
}

void Hospital::setRate(double rate)
{
	arrival_rate = rate;
}

void Hospital::setStaff(int nurses, int doctors) //Assign set number of nurses and doctors to staff
{
	for (int i = 0; i < nurses; i++) { //Put nurses at front of staff to access lower priority cases sooner
		Hospital*work = this;
		Caregiver* staffMember = new Nurse(work);
		staff.push_back(staffMember);
	}
	for (int i = 0; i < doctors; i++) { //Put doctors at back of staff to keep open for high priority cases
		Hospital*work = this;
		Caregiver* staffMember = new Doctor(work);
		staff.push_back(staffMember);
	}
}

void Hospital::admitPatient(int clock)
{
	int h = 0;
	Patient next_patient = waiting_room.top(); //Figure out who is next to be admitted
	while ((!waiting_room.empty()) && (h < staff.size()))
	{
			//If somebody is free and able to treat the patient
			if (((staff.at(h))->checkStatus() == false) && ((staff.at(h))->capable(next_patient)))
			{
				staff.at(h)->set_care(next_patient);
				staff.at(h)->treatPatient(clock);
				waiting_room.pop(); //Begin looking for next new patient
			}
			else
			{
				h++;
			}
			
	}
}


void Hospital::checkArrivals(int clock)
{
	if (my_random.next_double() < arrival_rate) {
		Patient new_arrival(citizens.at(my_random.next_int(citizens.size()))); //Select a random name from the citizens of 273ville
		new_arrival.setTime(clock);
		this->triage(new_arrival); 
	}
	if (!waiting_room.empty()) //If we have patients waiting
	{
		this->admitPatient(clock); //See if there is anybody open to treat patient.
	}
	check_patients(clock);
}

void Hospital::recordVisit(Patient treated, int clock)
{
	num_served++;
	records.insert(make_pair(treated.getName(), treated.getSeverity()));
	int visit = clock - treated.getArrival();
	avg_time = (visit + avg_time) / num_served;
}

int Hospital::calc_time()
{
	return avg_time;
}

void Hospital::display_records()
{
	std::vector<std::string> uniques;
	bool new_name = true;
	std::multimap<std::string, int>::iterator mit = records.begin();
	for (;mit != records.end(); mit++)
	{
		for (int i = 0; i < uniques.size(); i++)
		{
			if (uniques.at(i) == mit->first)
				new_name = false;
		}
		if (new_name == true)
			std::cout << mit->first << std::endl;
	}
}

void Hospital::search_records(std::string name)
{
	std::cout << "Records for " << name << ":" << std::endl;
	int visits = 0;
	std::multimap<std::string, int>::iterator mit = records.begin();
	for (; mit != records.end(); mit++)
	{
		if (mit->first == name)
		{
			visits++;
			std::cout << "Visit #" << visits << ":" << mit->second << std::endl;
		}
	}
}

void Hospital::check_patients(int clock)
{
	
	for (int i = 0; i < staff.size(); i++)
	{
		if (staff.at(i)->checkStatus() == true) 
		{
			staff.at(i)->treatPatient(clock);
		}
	}
}

int Hospital::getNum()
{
	return num_served;
}
