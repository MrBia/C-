#include "Dengue_Virus.h"



Dengue_Virus::Dengue_Virus()
{
	DoBorn();
}


Dengue_Virus::~Dengue_Virus()
{
}

Dengue_Virus::Dengue_Virus(const Dengue_Virus& vr)
{
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = vr.m_protein[i];
	}
}

Dengue_Virus::Dengue_Virus(char* protein)
{
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = protein[i];
	}
}

char* Dengue_Virus::Get_Protein()
{
	return this->m_protein;
}

void Dengue_Virus::DoBorn()
{
	LoadADNInformation();
	srand(time(0));
	int r = 1 + rand() % (3 + 1 - 1);
	if (r == 1) {
		this->m_protein[0] = 'N';
		this->m_protein[0] = 'S';
		this->m_protein[0] = '4';
	}
	else if (r == 2) {
		this->m_protein[0] = 'N';
		this->m_protein[0] = 'S';
		this->m_protein[0] = '5';
	}
	else {
		this->m_protein[0] = 'E';
	}
}

Virus** Dengue_Virus::DoClone()
{
	Virus** list = new Virus*[2];

	for (int i = 0; i < 2; i++) {
		/*list[i] = new Dengue_Virus(this->Get_Protein());
		list[i]->Set_dna(this->Get_dna());
		list[i]->Set_Resistance(this->Get_Resistance());*/
		list[i] = new Dengue_Virus(*this);
	}
	
	return list;
}

void Dengue_Virus::DoDie()
{
	this->Set_dna(NULL);
}

void Dengue_Virus::InitResistance()
{
	srand(time(0));
	int r;
	if (*(this->Get_Protein()+2) == '3') {
		r = 1 + rand() % (10 + 1 - 1);
	}
	else if (*(this->Get_Protein() + 2) == '5') {
		r = 11 + rand() % (20 + 1 - 11);
	}
	else {
		r = 21 + rand() % (30 + 1 - 21);
	}

	this->Set_Resistance(r);
	// or
	/*if (this->m_protein[2] == '3') {
		r = 1 + rand() % (10 + 1 - 1);
	}
	else if (this->m_protein[2] == '5') {
		r = 11 + rand() % (20 + 1 - 11);
	}
	else {
		r = 21 + rand() % (30 + 1 - 21);
	}*/
}
