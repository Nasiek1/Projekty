#pragma once
#include<iostream>
#include<memory>
#include"TerminalExpression.h"
class Operator : public TerminalExpression
{
protected:
	char character;
public:
	Operator();
	/*virtual std::unique_ptr<AbstractExpression> clone() const override
	{
		return std::make_unique<Operator>(*this);
	}*/
	Operator(const char& sign);
	bool operator==(const Operator& operat);
	char getCharacter();
	~Operator();
};
