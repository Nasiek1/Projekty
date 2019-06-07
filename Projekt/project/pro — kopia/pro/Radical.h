#pragma once
#include"Operator.h"
class Radical : public Operator
{

public:
	Radical();
	Radical(Radical&& move);
	~Radical();
};
