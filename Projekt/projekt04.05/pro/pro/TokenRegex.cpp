#include "TokenRegex.h"

TokenRegex::TokenRegex()
	:patternOperator("[-^+\\/*]"),
	plus("[+]"),
	patternNumber("(n?\\d+)?(\\.(\\d*))?"), 
	decimalNumber("(n?\\d+)?\\.(\\d*)?"), 
	integerNumber("n?\\d+"), 
	negation("(n\\d+)|(n(\\d+)?\\.(\\d*))?")
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
std::smatch TokenRegex::getMatchResult(const std::string &expression)
{
	std::smatch matchResult;
	std::regex_match(expression, matchResult, patternOperator);
	return matchResult;
	throw InvalidArgumentException();
}
token TokenRegex::checkTypeOperator(const std::string& expression)
{

	if (std::regex_match(expression, plus))
		return token{ PLUS };

	throw InvalidArgumentException();
}
token TokenRegex::checkTypeNumber(const std::string& expression)
{
	token number{ NUMBER };

	if (std::regex_match(expression, decimalNumber))
	{
		if (std::regex_match(expression, negation))
			number.value = -(std::stod(expression.substr(1, expression.size() - 1)));
		else
			number.value = std::stod(expression);
		return number;
	}
	if (std::regex_match(expression, integerNumber))
	{
		if (std::regex_match(expression, negation))
			number.value = -(std::stoi(expression.substr(1, expression.size() - 1)));
		else
			number.value = std::stoi(expression);
		return number;
	}
	throw InvalidArgumentException();
}
TokenRegex::~TokenRegex()
{
}
