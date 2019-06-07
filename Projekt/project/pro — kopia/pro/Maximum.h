#pragma once
#include"NonTerminalExpression.h"
#include"MaxOperator.h"
#include"Number.h"
#include"Parser.h"
class Maximum :public NonTerminalExpression
{
	MaxOperator max;

public:
	Maximum();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Maximum();
};