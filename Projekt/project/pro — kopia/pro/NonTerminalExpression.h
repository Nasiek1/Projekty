#pragma once
#include"AbstractExpression.h"
#include<vector> 
class NonTerminalExpression :public AbstractExpression
{

public:
	NonTerminalExpression();
	std::string emit();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr);
	~NonTerminalExpression();
};

