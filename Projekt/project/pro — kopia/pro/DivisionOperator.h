#pragma once
#include"Operator.h"
class DivisionOperator: public Operator
{

public:
	DivisionOperator();
	DivisionOperator(DivisionOperator&& move);
	~DivisionOperator();
};

