#include "MinOperator.h"



MinOperator::MinOperator()
	:Operator(" min ")
{
}

MinOperator::MinOperator(MinOperator&& move)
{
	character = std::move(move.character);
}
MinOperator::~MinOperator()
{
}
