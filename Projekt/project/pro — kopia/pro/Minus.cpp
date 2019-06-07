#include "Minus.h"

Minus::Minus()
	:Operator("-")
{
}

Minus::Minus(Minus&& move)
{
	character = std::move(move.character);
}
Minus::~Minus()
{
}
