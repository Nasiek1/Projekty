#include "InvalidOperandException.h"



InvalidOperandException::InvalidOperandException()
{
}

const char * InvalidOperandException::what() const noexcept
{
	return "Invalid operand";
}


InvalidOperandException::~InvalidOperandException()
{
}
