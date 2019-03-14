#pragma once
#include"TerminalExpression.h"
class Operator
{
	char character;
public:
	Operator();
	Operator(const char& sign);
	Operator(const Operator& copy);
	~Operator();
};

