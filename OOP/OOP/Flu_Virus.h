#pragma once
#include "Virus.h"

class Flu_Virus :public Virus
{
private:
	int m_color;
public:
	Flu_Virus();
	~Flu_Virus();
	Flu_Virus(int);
	void Set_Color(int);
	int Get_Color();

	void DoBorn();
	Virus** DoClone();
	void DoDie();
	void InitResistance();
};

