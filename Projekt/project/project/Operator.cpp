#include "Operator.h"
Operator::Operator()
{
}
Operator::Operator(const char& sign)
	:character(sign)
{

}
bool Operator::operator==(const Operator& operat)
{
	return character == operat.character;
}
Operator::Operator(const Operator& copy)
	:character(copy.character)
{

}
Operator::~Operator()
{
}
