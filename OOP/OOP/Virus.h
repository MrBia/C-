#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	~Virus();
	void Set_Resistance(int);
	int Get_Resistance();
	void Set_dna(char *);
	char* Get_dna();
	Virus(const Virus& vr);
	void LoadADNInformation();
	void ReduceResistance(int);

	virtual void DoBorn() = 0;
	virtual Virus* DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

