#pragma once
#include"Operator.h"
class Plus :public Operator
{
public:
	Plus();
	Plus(Plus&& move);
	~Plus();
};


