#pragma once
#include"Operator.h"
class Minus :public Operator
{
public:
	Minus();
	Minus(Minus&& move);
	~Minus();
};


