#include "patient.h"
#include <ctime>
#include <cstdlib>

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
	int k;
	int m = 200;
	
	r = random(10, 20);

	for (int i = 0; i < r; i++) {
		k = random(1, 30);

		Virus* vr;
		if (k % 2 == 0) {
			vr = new Flu_Virus;
			
		}
		else {
			vr = new Dengue_Virus;
			
		}
		this->m_virusList.push_back(vr);
		m += 150;
	}

	this->m_state = 1;
}

void patient::TakeMedicine(int medicine_resistance)
{

	int Total_Virus_Resistance = 0;
	list<Virus*>::iterator virut = this->m_virusList.begin();
	list<Virus*>::iterator tempVirut;
	int len = this->m_virusList.size();
	int l = 0;
	
	while (virut != this->m_virusList.end() && l < len) {
		(**virut).ReduceResistance(medicine_resistance);

		if ((**virut).Get_Resistance() <= 0) {
			tempVirut = virut;
			virut++;
			l++;
			this->m_virusList.erase(tempVirut);
			continue;
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
			Total_Virus_Resistance += (**virut).Get_Resistance();
		}
		virut++;
		l++;
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
	int r;
	r = min + rand() % (max + 1 - min);
	return r;
}

void patient::show()
{
	cout << "state: " << this->m_state << "\n";
	cout << "resistance: " << this->m_resistance << "\n";
	cout << "number virus: " << this->m_virusList.size() << "\n";
	cout << "list virus: \n\n";
	
	list<Virus*>::iterator vr;
	for (vr = this->m_virusList.begin(); vr != this->m_virusList.end(); vr++) {
		(**vr).show();

		cout << "\n";
	}
}
