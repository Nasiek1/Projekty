#pragma once
#include<regex>
#include<vector>
#include<memory>
#include"Token.h"
#include"InvalidArgumentException.h"
class TokenRegex
{
	std::regex patternOperator;
	std::regex plus;
	std::regex minus;
	std::regex asterisk;
	std::regex slash;
	std::regex power;
	std::regex radical;
	std::regex max;
	std::regex min;
	std::regex patternNumber;
	std::regex decimalNumber;
	std::regex negation;
	std::regex integerNumber;
public:
	bool isTerminalOperator(const std::string &expression);
	bool isTerminalNumber(const std::string& expression);
	std::smatch getMatchResult(const std::string &expression);
	token checkTypeOperator(const std::string& expression);
	token checkTypeNumber(const std::string& expression);

	TokenRegex();
	~TokenRegex();
};

