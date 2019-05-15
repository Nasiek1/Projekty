#pragma once
#include"Lexer.h"
#include"Token.h"
#include<stack>
#include"Number.h"
#include"Operator.h"
#include<variant>
#include"Addition.h"
#include<memory>

class Parser
{
	std::unique_ptr<Lexer> lexer;
	token  currentToken;
public:
	Parser();
	Parser(const std::string & expression);
	std::string getData();
	void setData(const std::string & newData);
	std::unique_ptr<AbstractExpression> parse();
	Parser(Parser && other) = default;
	Parser& operator=(Parser&& other) = default;
	~Parser();
};

