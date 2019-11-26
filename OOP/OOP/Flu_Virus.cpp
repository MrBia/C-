#include "Flu_Virus.h"



Flu_Virus::Flu_Virus()
{
	this->DoBorn();
	this->InitResistance();
}


Flu_Virus::~Flu_Virus()
{
	this->DoDie();
}

Flu_Virus::Flu_Virus(const Flu_Virus& vr):Virus(vr)
{
	this->m_color = vr.m_color;

}



void Flu_Virus::Set_Color(int color)
{
	this->m_color = color;
}

int Flu_Virus::Get_Color()
{
	return this->m_color;
}

void Flu_Virus::DoBorn() {
	LoadADNInformation();

	int r = random(1, 100);

	if(r % 2 == 0) this->m_color = 1;     // red virus
	else this->m_color = 2;               // blue virus
}

Virus** Flu_Virus::DoClone()              
{
	Virus** list = new Virus*[1];

	list[0] = new Flu_Virus(*this);

	return list;
}

void Flu_Virus::DoDie()
{
	this->Set_Color(0);
	this->Set_Resistance(0);
	this->Set_dna(NULL);
}

void Flu_Virus::InitResistance() {
	int r = 0;
	
	if (this->m_color == 1) {               // red virus
		r = random(10, 20);

	}
	else if (this->m_color == 2){           // blue color
		r = random(10, 15);

	}
	
	this->Set_Resistance(r);
}

void Flu_Virus::show()
{
	cout << "Flu virus: \n";
	if (this->m_color == 1) cout << "color of virus: RED\n";
	else cout << "color of virus: BLUE\n";
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
	cout << "\n";
	cout << "resistance: " << this->Get_Resistance() << "\n\n";
}

int Flu_Virus::random(int min, int max)
{
	int k = min + rand() % (max + 1 - min);
	return k;
}
