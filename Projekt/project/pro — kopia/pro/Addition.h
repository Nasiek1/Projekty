#pragma once
#include"NonTerminalExpression.h"
#include"Plus.h"
#include"Number.h"
#include"Parser.h"
class Addition :public NonTerminalExpression
{
	Plus plus;

public:
	Addition();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot); 
	void checkAST(); 
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot,Parser& parser);
	~Addition();
};
