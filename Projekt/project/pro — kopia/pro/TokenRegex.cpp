#include "TokenRegex.h"

TokenRegex::TokenRegex()
	:patternOperator("[-^+\\/*]|root|max|min"),
	plus("[+]"),
	minus("[-]"),
	asterisk("[*]"),
	slash("[\\/]"),
	power("[^]"),
	radical("(root)"),
	max("(max)"),
	min("(min)"),
	patternNumber("(n?\\d+)?(\\.(\\d*))?"), 
	decimalNumber("(n?\\d+)?\\.(\\d*)?"), 
	integerNumber("n?\\d+"), 
	negation("(n\\d+)|(n(\\d+)?\\.(\\d*))?")
{
	
}
bool TokenRegex::isTerminalOperator(const std::string &expression) //function to check if token represents operator
{
	return std::regex_match(expression, patternOperator);
}
bool TokenRegex::isTerminalNumber(const std::string& expression) //function to check if token represents number
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
token TokenRegex::checkTypeOperator(const std::string& expression) // function to check type of token, knowing that it's operator
{

	if (std::regex_match(expression, plus))
		return token{ PLUS };
	if (std::regex_match(expression, minus))
		return token{ MINUS };
	if (std::regex_match(expression, asterisk))
		return token{ ASTERISK };
	if (std::regex_match(expression, slash))
		return token{ SLASH };
	if (std::regex_match(expression, power))
		return token{ POWER };
	if (std::regex_match(expression, radical))
		return token{ RADICAL };
	if (std::regex_match(expression, max))
		return token{ MAX };
	if (std::regex_match(expression, min))
		return token{ MIN };
	throw InvalidArgumentException();
}
token TokenRegex::checkTypeNumber(const std::string& expression) // function to check type of token's value, knowing that it's number
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
