#include "Operator.h"
Operator::Operator()
{
}
Operator::Operator(const std::string& sign)
	:character(sign)
{

}
std::string Operator::getCharacter()
{
	return character;
}
void Operator::setCharacter(const std::string & sign)
{
	character = sign;
}
bool Operator::operator==(const Operator& operat)
{
	return character == operat.character;
}

Operator::~Operator()
{
}
