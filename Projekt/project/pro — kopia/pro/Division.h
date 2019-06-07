#pragma once
#include"NonTerminalExpression.h"
#include"DivisionOperator.h"
#include"Number.h"
#include"InvalidOperandException.h"
#include"Parser.h"
class Division :public NonTerminalExpression
{
	DivisionOperator backslash;

public:
	Division();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Division();
};
