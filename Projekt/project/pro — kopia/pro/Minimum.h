#pragma once
#include"NonTerminalExpression.h"
#include"MinOperator.h"
#include"Number.h"
#include"Parser.h"
class Minimum :public NonTerminalExpression
{
	MinOperator min;

public:
	Minimum();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Minimum();
};
