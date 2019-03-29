#pragma once
#include<memory>
#include"AbstractExpression.h"
class TerminalExpression:public AbstractExpression
{	
public:
	TerminalExpression();
	~TerminalExpression();
};

