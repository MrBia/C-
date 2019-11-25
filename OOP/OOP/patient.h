#pragma once
#include <list>
#include "Virus.h"
#include "Flu_Virus.h"
#include "Dengue_Virus.h"

class patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
public:
	patient();
	~patient();
	double InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int GetState();
	int random(int, int);
	void show();
};

