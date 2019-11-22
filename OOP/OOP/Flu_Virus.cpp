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

void Flu_Virus::DoBorn() {
	LoadADNInformation();
	srand(time(0));
	int r = 0 + rand() % (255 + 1 - 0);

	if(r % 2 == 0) this->m_color = 1;     // red virus
	else this->m_color = 2;               // blue virus
}

void Flu_Virus::InitResistance() {
	srand(time(0));
	int r;
	if (this->m_color == 1) {               // red virus
		r = 10 + rand() % (20 + 1 - 10);
	}
	else if (this->m_color == 2){           // blue color
		r = 10 + rand() % (15 + 1 - 10);
	}

	Set_Resistance(r);
}
