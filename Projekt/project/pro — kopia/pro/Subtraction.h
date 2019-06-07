#pragma once
#include"NonTerminalExpression.h"
#include"Minus.h"
#include"Number.h"
#include"Parser.h"
class Subtraction :public NonTerminalExpression
{
	Minus minus;

public:
	Subtraction();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Subtraction();
};
