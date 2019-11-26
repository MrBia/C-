#include "Virus.h"


Virus::Virus()
{
	this->m_dna = NULL;
}


Virus::~Virus()
{
	delete[] this->m_dna;
	this->m_dna = NULL;
}

void Virus::Set_Resistance(int resistance) {
	this->m_resistance = resistance;
}

int Virus::Get_Resistance()
{
	return this->m_resistance;
	
}

void Virus::Set_dna(char* dna)
{
	this->m_dna = dna;
}

char* Virus::Get_dna()
{
	return this->m_dna;
}

Virus::Virus(const Virus& vr)
{
	int i = 0;
	int size = 0;
	while (true) {
		if (vr.m_dna[i] == 'A' || vr.m_dna[i] == 'T' || vr.m_dna[i] == 'G' || vr.m_dna[i] == 'X') size++;
		else break;
		i++;
	}
	
	this->m_dna = new char[size];
	for (int i = 0; i < size; i++) {
		this->m_dna[i] = vr.m_dna[i];
	}
	this->m_resistance = vr.m_resistance;
}

void Virus::LoadADNInformation()
{
	string dna = "";
	ifstream file;
	file.open("C:/Users/Admin/Desktop/C-/OOP/ATGX.bin");
	if (!file) {
		cout << "khong the mo file!\n";
	}
	else {
		while (!file.eof()) {
			string s;
			getline(file, s);
			dna = dna + s;
		}
	}
	
	this->m_dna = new char[dna.size()];
	for (int i = 0; i < dna.size(); i++) {
		this->m_dna[i] = dna[i];
	}

}

void Virus::ReduceResistance(int medicine_resistance) {
	this->m_resistance -= medicine_resistance;
}

