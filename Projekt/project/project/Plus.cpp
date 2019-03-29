#include "Plus.h"



Plus::Plus()
	:Operator('+')
{
}

Plus::Plus(const Plus& copy)
{
	character = copy.character;
}
Plus::~Plus()
{
}
