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
	 Parser parser;
public:
	Interpreter(const std::string & data);
	void interpret();
	std::string determineInfixForm(std::string & infixForm,std::unique_ptr<AbstractExpression>& root, bool is_root);
	void checkASTCorrectness(std::unique_ptr<AbstractExpression> & root);
	std::unique_ptr<AbstractExpression>& getpRoot();
	void emit(std::unique_ptr<AbstractExpression>& root);
	double calculate(std::unique_ptr<AbstractExpression>& root);
	virtual ~Interpreter();
};

