#pragma once
#include "Virus.h"

class Dengue_Virus : public Virus
{
private:
	char m_protein[4];
public:
	Dengue_Virus();
	~Dengue_Virus();
	Dengue_Virus(const Dengue_Virus& vr);
	//Dengue_Virus(char *);
	char* Get_Protein();

	void show();
	void DoBorn();
	Virus** DoClone();
	void DoDie();
	void InitResistance();
};

