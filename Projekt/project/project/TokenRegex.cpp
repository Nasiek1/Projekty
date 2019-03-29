#include "TokenRegex.h"

TokenRegex::TokenRegex()
	:patternOperator("[*+\-^/]"),
	plus("[+]"),
	minus("[-]"),
	multi("[*]"),
	div("[/]"),
	exponent("[^]"),
	patternNumber("[+-]?\d+\.?\d*"),
	decimalNumber("([+-]?\d+)?\.\d*")
{

}
bool TokenRegex::isTerminalOperator(const std::string &expression)
{
	return std::regex_match(expression, patternOperator);
}
bool TokenRegex::isTerminalNumber(const std::string& expression)
{
	return std::regex_match(expression, patternNumber);
}
std::regex TokenRegex::getPlus()
{
	return plus;
}
std::regex TokenRegex::getNumber()
{
	return decimalNumber;
}
TokenRegex::~TokenRegex()
{
}
