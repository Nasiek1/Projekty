#include"IncorrectDataException.h"
const char* IncorrectDataException::what() const noexcept
{
	return "Incorrect data from file";
}
IncorrectDataException::IncorrectDataException()
{

}
IncorrectDataException::~IncorrectDataException()
{

}