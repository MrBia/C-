#include "Dengue_Virus.h"



Dengue_Virus::Dengue_Virus()
{
	this->DoBorn();
	this->InitResistance();
}


Dengue_Virus::~Dengue_Virus()
{
}

Dengue_Virus::Dengue_Virus(const Dengue_Virus& vr) :Virus(vr)
{
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = vr.m_protein[i];
	}
}

//Dengue_Virus::Dengue_Virus(char* protein)
//{
//	for (int i = 0; i < 4; i++) {
//		this->m_protein[i] = protein[i];
//	}
//}

char* Dengue_Virus::Get_Protein()
{
	return this->m_protein;
}

void Dengue_Virus::show()          // override
{
	cout << "Dengue virus: \n";
	cout << "protein: ";
	for (int i = 0; i < 4; i++) {
		if (this->m_protein[i] == 'N' || this->m_protein[i] == 'S' || this->m_protein[i] == '4' ||
			this->m_protein[i] == '5' || this->m_protein[i] == 'E')
			cout << this->m_protein[i];
	}
	cout << "\n";
	cout << "dna: ";
	char* s = this->Get_dna();
	int i = 0;
	int size = 0;
	while (true) {
		if (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'X') size++;
		else break;
		i++;
	}
	for (int i = 0; i < size; i++) {
		cout << s[i];
	}
	s = NULL;
	cout << "\n";
	cout << "resistance: " << this->Get_Resistance() << "\n\n";
}

void Dengue_Virus::DoBorn()
{
	LoadADNInformation();
	

	//srand(time(0));
	int r = 1 + rand() % (3 + 1 - 1);
	if (r == 1) {
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '4';
	}
	else if (r == 2) {
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '5';
	}
	else {
		this->m_protein[0] = 'E';
	}
	
}

//Virus* Dengue_Virus::DoClone()
//{
//	Virus* list1[1];
//	for (int i = 0; i < 1; i++) {
//
//		list1[i] = new Dengue_Virus(*this);
//		
//	}
//	return list1[0];
//}

list<Virus*> Dengue_Virus::DoClone() {
	list<Virus*> lis;
	Virus* v;
	for (int i = 0; i < 2; i++) {
		v = new Dengue_Virus(*this);
		lis.push_back(v);
		v = NULL;
	}
	return lis;
}

void Dengue_Virus::DoDie()
{
	this->Set_dna(NULL);
}

void Dengue_Virus::InitResistance()
{
	int r = 9;
	if (*(this->Get_Protein() + 2) == '3') {
		r = 1 + rand() % (10 + 1 - 1);
	}
	else if (*(this->Get_Protein() + 2) == '5') {
		r = 11 + rand() % (20 + 1 - 11);
	}
	else {
		r = 21 + rand() % (30 + 1 - 21);

	}

	this->Set_Resistance(r);
	
}
