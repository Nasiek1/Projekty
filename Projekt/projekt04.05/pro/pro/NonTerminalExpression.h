#pragma once
#include"AbstractExpression.h"

class NonTerminalExpression :public AbstractExpression
{
	
public:
	/*virtual std::unique_ptr<AbstractExpression> clone() const override
	{
		return std::make_unique<NonTerminalExpression>(*this);
	}*/
	NonTerminalExpression();
	NonTerminalExpression(const std::string newData);
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData);
	~NonTerminalExpression();
};

