#pragma once
#include"NonTerminalExpression.h"
#include"MultiplicationOperator.h"
#include"Number.h"
#include"Parser.h"
class Multiplication :public NonTerminalExpression
{
	MultiplicationOperator asterisk;

public:
	Multiplication();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Multiplication();
};
