#pragma once
#pragma once
#include"NonTerminalExpression.h"
#include"Power.h"
#include"Number.h"
#include"Parser.h"
class Exponentiation :public NonTerminalExpression
{
	Power caret;

public:
	Exponentiation();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~Exponentiation();
};