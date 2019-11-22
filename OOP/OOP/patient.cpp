#include "patient.h"
#include <time.h>


patient::patient()
{
	this->m_resistance = random(1000, 9000);
	DoStart();
}


patient::~patient()
{
}

double patient::InitResistance()
{
	return 0.0;
}

void patient::DoStart()
{
	int r;
	r = random(10, 20);
	for (int i = 0; i < r; i++) {
		int k = random(1, 10);
		Virus* vr;
		if (k % 2 == 0) {
			vr = new Flu_Virus;
		}
		else {
			vr = new Dengue_Virus;
		}
		this->m_virusList.push_back(vr);
	}

	this->m_state = 1;
}

void patient::TakeMedicine(int medicine_resistance)
{
	int Total_Virus_Resistance = 0;
	list<Virus*>::iterator virut;
	for (virut = this->m_virusList.begin(); virut != this->m_virusList.end(); virut++) {
		(**virut).ReduceResistance(medicine_resistance);
		if ((**virut).Get_Resistance() <= 0) {
			this->m_virusList.erase(virut);
		}
		else {
			Virus** virus_clone = (**virut).DoClone();
			if (sizeof(**virus_clone) == sizeof(Dengue_Virus)) {							// if return 2 virut        Dengue_Virus
				this->m_virusList.push_back(*virus_clone);									// push_front
				this->m_virusList.push_back(*(virus_clone + 1));				// neu push_back thi virus tao ra se -resistance 1 lan nua			
			}
			else {																			// if return 1 virut		 Flu_Virus
				this->m_virusList.push_back(*virus_clone);
			}
		}
		// total resistance
		Total_Virus_Resistance += (**virut).Get_Resistance();
	}

	if (Total_Virus_Resistance > this->m_resistance) {
		DoDie();
	}
}

void patient::DoDie()
{
	this->m_state = 0;
	list<Virus*>::iterator virut;
	for (virut = this->m_virusList.begin(); virut != this->m_virusList.end(); virut++) {
		delete* virut;
	}
}

int patient::GetState()
{
	return this->m_state;
}

int patient::random(int min, int max)
{
	srand(time(0));
	int r;
	r = min + rand() % (max + 1 - min);
	return r;
}
