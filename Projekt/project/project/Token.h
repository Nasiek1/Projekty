#pragma once
#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include"AbstractExpression.h"
#include<regex>	
#include"TokenRegex.h"
class Token
{
	std::string data;
	TokenRegex pattern;
public:
	Token(const std::string & information);
//	std::unique_ptr<AbstractExpression>createTerminalNumber(const std::string& expression);
	//std::unique_ptr<AbstractExpression> createTerminalOperator(const std::string &expression);
	/*std::vector<std::unique_ptr<AbstractExpression>>*/ void splitIntoToken();
	~Token();
};

