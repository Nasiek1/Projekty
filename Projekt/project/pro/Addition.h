#pragma once
#include"NonTerminalExpression.h"
#include"Plus.h"
#include"Number.h"
class Addition :public NonTerminalExpression
{
	Plus plus;

public:
	Addition();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot); //zakladamy ze double? 
	void checkAST(); //czy nie ma pustych lisci
	void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr);
	Addition(Addition&& add);
	
	~Addition();
};
