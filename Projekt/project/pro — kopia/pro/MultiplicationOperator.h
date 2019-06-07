#pragma once
#include"Operator.h"
class MultiplicationOperator: public Operator
{
public:
	MultiplicationOperator();
	MultiplicationOperator(MultiplicationOperator&& move);
	~MultiplicationOperator();
};

