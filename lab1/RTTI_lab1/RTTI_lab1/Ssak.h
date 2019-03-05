#pragma once
#include<iostream>
class Ssak
{
	double waga;
public:
	Ssak();
	Ssak(const double weight);
	virtual ~Ssak();
	virtual void jedz();
	double getWaga();
	
};

