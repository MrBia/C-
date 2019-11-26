#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include <time>
//#include <cstdlib>
using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	virtual ~Virus();
	void Set_Resistance(int);
	int Get_Resistance();
	void Set_dna(char *);           //danger
	char* Get_dna();
	Virus(const Virus& vr);
	void LoadADNInformation();
	void ReduceResistance(int);

	virtual void show() = 0;
	virtual void DoBorn() = 0;
	virtual Virus** DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

