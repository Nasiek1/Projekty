#pragma once
#include"AbstractExpression.h"
class TerminalExpression:public AbstractExpression 
{
	int priority;
public:
	TerminalExpression();
	TerminalExpression(const int& prior);
	//bool operator==(const TerminalExpression& terminalExp);
	~TerminalExpression();
};

