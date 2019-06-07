#pragma once
#include"Operator.h"
class MaxOperator : public Operator
{

public:
	MaxOperator();
	MaxOperator(MaxOperator&& move);
	~MaxOperator();
};
