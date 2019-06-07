#include "InvalidArgumentException.h"



InvalidArgumentException::InvalidArgumentException()
{
}
const char* InvalidArgumentException::what() const noexcept
{
	return "Invalid argument in string";
}
InvalidArgumentException::~InvalidArgumentException()
{
}
