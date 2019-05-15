#include "Plus.h"



Plus::Plus()
	:Operator("+")
{
}

Plus::Plus(Plus&& move)
{
	character = std::move(move.character);
}
Plus::~Plus()
{
}
