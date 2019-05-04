#pragma once //czy uzywac namespace Interpreter a do Expression interfejs?
//#include"Parser.h"
#include"AbstractExpression.h"
#include<memory>
#include"Parser.h"
class Interpreter
{
	
protected:
	 std::unique_ptr<AbstractExpression> pRoot;
public:
	Interpreter();
	void interpret();
	virtual ~Interpreter();
};

