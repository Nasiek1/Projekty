#include "MaxOperator.h"



MaxOperator::MaxOperator()
	:Operator(" max ")
{
}

MaxOperator::MaxOperator(MaxOperator&& move)
{
	character = std::move(move.character);
}

MaxOperator::~MaxOperator()
{
}
