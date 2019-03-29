#pragma once
#include<iostream>
#include<memory>
#include"TerminalExpression.h"
class Operator: public TerminalExpression
{
protected:
	char character;
public:
	Operator();
	Operator(const char& sign);
	bool operator==(const Operator& operat);
	Operator(const Operator& copy);
	~Operator();
};

