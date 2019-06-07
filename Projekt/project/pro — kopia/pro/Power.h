#pragma once
#include"Operator.h"
class Power : public Operator
{

public:
	Power();
	Power(Power&& move);
	~Power();
};

