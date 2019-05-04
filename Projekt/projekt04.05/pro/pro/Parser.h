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
	std::string getData();
	void setData(const std::string & newData);
	std::unique_ptr<AbstractExpression> parse();
	~Parser();
	//Parser(const AbstractExpression& expr);
	Parser(const Parser& other);
	Parser(Parser && other) = default;
	Parser& operator=(const Parser & other);
	Parser& operator=(Parser&& other) = default;
};

