#include "Operator.h"
Operator::Operator()
{
}
Operator::Operator(const char& sign)
	:character(sign)
{

}
char Operator::getCharacter()
{
	return character;
}
bool Operator::operator==(const Operator& operat)
{
	return character == operat.character;
}

Operator::~Operator()
{
}
