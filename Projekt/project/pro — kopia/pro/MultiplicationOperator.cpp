#include "MultiplicationOperator.h"

MultiplicationOperator::MultiplicationOperator()
	:Operator("*")
{
}
MultiplicationOperator::MultiplicationOperator(MultiplicationOperator&& move)
{
	character = std::move(move.character);
}
MultiplicationOperator::~MultiplicationOperator()
{
}
