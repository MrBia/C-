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

Flu_Virus::Flu_Virus(const Flu_Virus& vr)
{
	this->m_color = vr.m_color;
}

//Flu_Virus::Flu_Virus(int color)
//{
//	this->m_color = color;
//}

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
	srand(time(0));
	int r = 0 + rand() % (255 + 1 - 0);

	if(r % 2 == 0) this->m_color = 1;     // red virus
	else this->m_color = 2;               // blue virus
}

Virus** Flu_Virus::DoClone()              // khi ra khoi ham thi con tro vr co bi huy khong ????????????????? saiiiiiiiiiiiii
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
	srand(time(0));
	int r;
	if (this->m_color == 1) {               // red virus
		r = 10 + rand() % (20 + 1 - 10);
	}
	else if (this->m_color == 2){           // blue color
		r = 10 + rand() % (15 + 1 - 10);
	}

	this->Set_Resistance(r);
}
