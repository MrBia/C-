#include "patient.h"
#include <ctime>
#include <cstdlib>

patient::patient()
{
	this->m_state = 0;
	this->m_virusList;
	this->m_resistance = random(1000, 9000);
	DoStart();
}


patient::~patient()
{
	//DoDie();
	list<Virus*>::iterator virut = m_virusList.begin();
	while (virut != this->m_virusList.end()) {
		delete *virut;
		virut++;
	}
	this->m_virusList.clear();
}

double patient::InitResistance()
{
	return 0.0;
}

void patient::DoStart()
{

	int r;
	int k;
	
	r = random(10, 20);
	Virus* vr;
	for (int i = 0; i < r; i++) {
		k = random(1, 30);
		
		if (k % 2 == 0) {
			vr = new Flu_Virus;        // leak
			
		}
		else {
			vr = new Dengue_Virus;		// no leak
			
		}
	
		this->m_virusList.push_back(vr);
	}

	this->m_state = 1;
}

void patient::TakeMedicine(int medicine_resistance)
{

	int Total_Virus_Resistance = 0;
	list<Virus*>::iterator virut = this->m_virusList.begin();

	int len = this->m_virusList.size();
	int l = 0;
	
	while (virut != this->m_virusList.end() && l < len) {
		(**virut).ReduceResistance(medicine_resistance);

		if ((**virut).Get_Resistance() <= 0) {
			l++;
			Virus* v = *virut;
			virut = this->m_virusList.erase(virut);
			delete v;
		}
		else {
			list<Virus*> lis = (**virut).DoClone();
			list<Virus*>::iterator i;
			for (i = lis.begin(); i != lis.end(); i++) {
				this->m_virusList.push_back(*i);
				*i = NULL;
			}


			//Virus* virus_clone = (**virut).DoClone();
			//if (sizeof(*virus_clone) == sizeof(Dengue_Virus)) {							// if return 2 virut        Dengue_Virus
			//	this->m_virusList.push_back(virus_clone);
			//	//this->m_virusList.push_back(v + 1);
			//	virus_clone = NULL;
			//}
			//else {																			// if return 1 virut		 Flu_Virus
			//	this->m_virusList.push_back(virus_clone);
			//	virus_clone = NULL;
			//}
			
			Total_Virus_Resistance += (**virut).Get_Resistance();
			virut++;
			l++;
		}
	}
	

	if (Total_Virus_Resistance > this->m_resistance) {
		DoDie();
	}
}

void patient::DoDie()
{
	this->m_state = 0;
	list<Virus*>::iterator virut = m_virusList.begin();
	while (virut != this->m_virusList.end()) {
		delete *virut;
		virut++;
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
