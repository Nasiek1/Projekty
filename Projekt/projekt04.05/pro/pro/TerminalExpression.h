#pragma once
#include<memory>
#include"AbstractExpression.h"
class TerminalExpression :public AbstractExpression
{
public:
	TerminalExpression();
	TerminalExpression(const std::string & newData);
	/*virtual std::unique_ptr<AbstractExpression> clone() const override
	{
		return std::make_unique<TerminalExpression>(*this);
	}*/
	void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData);
	~TerminalExpression();
};

