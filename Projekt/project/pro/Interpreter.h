#pragma once 
#include"AbstractExpression.h"
#include<memory>
#include"Parser.h"
#include<string>
#include<vector>
#include"SyntaxErrorException.h"
class Interpreter
{
protected:
	 std::unique_ptr<AbstractExpression> pRoot;
	 std::unique_ptr<Parser> parser;
public:
	Interpreter();
	Interpreter(const std::string & data);
	void interpret();
	void checkASTCorrectness(std::unique_ptr<AbstractExpression> & root);
	std::unique_ptr<AbstractExpression>& getpRoot();
	void emit(std::unique_ptr<AbstractExpression>& root);
	double calculate(std::unique_ptr<AbstractExpression>& root);
	virtual ~Interpreter();
};

