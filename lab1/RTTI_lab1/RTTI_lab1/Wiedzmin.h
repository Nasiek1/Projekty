#pragma once
#include"Czlowiek.h"
class Wiedzmin: public Czlowiek
{
	double dmg;
public:
	Wiedzmin();
	Wiedzmin(const double weight, const char *name, const int iQ, const double damage);
	~Wiedzmin();
	void bij_potwora();
	void jedz();
	void ucz_sie();
	double getDamage();
};

