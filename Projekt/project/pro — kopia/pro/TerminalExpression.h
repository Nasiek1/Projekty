#pragma once
#include<memory>
#include"AbstractExpression.h"
#include<vector>
class TerminalExpression :public AbstractExpression
{
public:
	TerminalExpression();
	std::string emit();
	void checkAST();
	double calcuate(std::unique_ptr<AbstractExpression>& pRoot);
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser& parser);
	void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr);
	~TerminalExpression();
};

