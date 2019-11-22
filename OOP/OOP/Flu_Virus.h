#pragma once
#include "Virus.h"
#include <time.h>
class Flu_Virus :public Virus
{
private:
	int m_color;
public:
	Flu_Virus();
	~Flu_Virus();

	void DoBorn();
	Virus* DoClone();
	void DoDie();
	void InitResistance();
};

