#include "Operator.h"
Operator::Operator()
{
}
Operator::Operator(const char& sign)
	:character(sign)
{

}
Operator::Operator(const Operator& copy)
	:character(copy.character)
{

}
Operator::~Operator()
{
}
