#pragma once
#include<regex>
#include<vector>
#include<memory>
class TokenRegex
{
	std::regex patternOperator;
	std::regex plus;
	std::regex minus;
	std::regex multi;
	std::regex div;
	std::regex exponent;
	std::regex patternNumber;
	std::regex decimalNumber;
public:
	bool isTerminalOperator(const std::string &expression);
	bool isTerminalNumber(const std::string& expression);
	std::regex getPlus();
	std::regex getNumber();
	TokenRegex();
	~TokenRegex();
};

