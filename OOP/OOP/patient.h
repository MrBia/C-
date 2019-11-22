#pragma once
#include <list>
#include "Virus.h"

//using namespace std;  - list      da co trong virus.h 
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
	void TakeMedicine();
	void DoDie();
	int GetState();
};

