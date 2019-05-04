#pragma once
#include"Operator.h"
class Plus :public Operator
{
public:
	Plus();
	/*virtual std::unique_ptr<AbstractExpression> clone() const override
	{
		return std::make_unique<Plus>(*this);
	}*/
	Plus(Plus&& move);
	~Plus();
};


