#pragma once
#include"NonTerminalExpression.h"
#include"Radical.h"
#include"Number.h"
#include"InvalidOperandException.h"
#include"Parser.h"
#include<functional>
class RootExtraction :public NonTerminalExpression
{
	Radical radical;

public:
	RootExtraction();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	~RootExtraction();
};

