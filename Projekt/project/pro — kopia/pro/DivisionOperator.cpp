#include "DivisionOperator.h"

DivisionOperator::DivisionOperator()
	:Operator("/")
{
	
}
DivisionOperator::DivisionOperator(DivisionOperator&& move)
{
	character = std::move(move.character);
}
DivisionOperator::~DivisionOperator()
{
}
