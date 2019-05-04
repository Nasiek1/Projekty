#pragma once
#include"NonTerminalExpression.h"
class Addition :public NonTerminalExpression
{
	//liczba operator liczba????
protected:
	//virtual Addition* clone_impl() const override { return new Addition(); };
	
public:
	//virtual std::unique_ptr<AbstractExpression> clone() const override
	//{
	//	return std::make_unique<Addition>(*this);
	//}
	Addition();
	Addition(const std::string & newData);
	void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData);
	Addition(Addition&& add);
	~Addition();
};
