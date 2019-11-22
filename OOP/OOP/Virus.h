#pragma once
//#include <iostream>
using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	~Virus();
	Virus(char*, int);
	void LoadADNInformation();
	//void ReduceResistance();

	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

