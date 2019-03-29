#pragma once
#include<memory>
#include<vector>
#include"TokenStreamSelector.h"
#include<utility>
class AbstractExpression
{
protected:
	std::vector<std::unique_ptr<AbstractExpression>> expression;
public:
	AbstractExpression();
	AbstractExpression(std::vector<std::unique_ptr<AbstractExpression>>& expr);
	~AbstractExpression();
};

