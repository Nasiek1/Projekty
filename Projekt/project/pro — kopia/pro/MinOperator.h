#pragma once
#include"Operator.h"
class MinOperator : public Operator
{

public:
	MinOperator();
	MinOperator(MinOperator&& move);
	~MinOperator();
};
