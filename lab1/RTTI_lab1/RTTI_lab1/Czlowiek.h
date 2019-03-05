#pragma once
#include<iostream>
#include"Ssak.h"
class Czlowiek: public Ssak
{
	char *imie;
	int iq;
public:
	Czlowiek();
	Czlowiek(const double weight, const char *name, const int iQ);
	~Czlowiek();
	virtual void jedz();
	virtual void ucz_sie();
};

