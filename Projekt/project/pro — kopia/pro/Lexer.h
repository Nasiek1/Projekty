#pragma once
#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include"AbstractExpression.h"
#include<regex>	
#include"TokenRegex.h"
#include"Token.h"
#include"InvalidArgumentException.h"
#include"InputStream.h"
class Lexer
{
	std::string data;
	TokenRegex pattern;
public:
	Lexer(const std::string & information);
	std::string getData();
	void setData(const std::string & newData);
	token getToken();
	~Lexer();
};

