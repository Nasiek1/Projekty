#include "SyntaxErrorException.h"



const char * SyntaxErrorException::what() const noexcept
{
	return "Syntax Error";
}

SyntaxErrorException::SyntaxErrorException()
{
}


SyntaxErrorException::~SyntaxErrorException()
{
}
