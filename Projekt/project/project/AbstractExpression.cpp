#include "AbstractExpression.h"
AbstractExpression::AbstractExpression()
{

}
AbstractExpression::AbstractExpression(std::vector<std::unique_ptr<AbstractExpression>>& expr)
	:expression(std::move(expr))
{
	
}

AbstractExpression::~AbstractExpression()
{
}

