#include "Virus.h"


Virus::Virus()
{
}


Virus::~Virus()
{
}

void Virus::Set_Resistance(int resistance) {
	this->m_resistance = resistance;
}

Virus::Virus(const Virus& vr)
{
	this->m_dna = vr.m_dna;
	this->m_resistance = vr.m_resistance;
}

void Virus::LoadADNInformation()
{
	string dna = "";
	ifstream file;
	file.open("C:\Users\Admin\Desktop\C-\OOP\ATGX.bin");
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
	m_dna = new char[dna.length()];
	for (int i = 0; i < dna.length(); i++) {
		*m_dna = dna[i];
	}
}

void Virus::ReduceResistance(int medicine_resistance) {
	this->m_resistance -= medicine_resistance;
}
