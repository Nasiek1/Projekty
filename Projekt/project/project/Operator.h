#pragma once
#include"TerminalExpression.h"
class Operator: public TerminalExpression
{
	char character;
public:
	Operator();
	Operator(const int &prior, const char& sign);
	bool operator==(const Operator& operat);
	Operator(const Operator& copy);
	~Operator();
};

