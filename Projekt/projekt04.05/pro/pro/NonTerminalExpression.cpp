#include "NonTerminalExpression.h"
#include"Parser.h"
void NonTerminalExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData)
{

	
	
}

NonTerminalExpression::NonTerminalExpression()
{
}

NonTerminalExpression::NonTerminalExpression(const std::string newData)
	:AbstractExpression(newData)
{
}


NonTerminalExpression::~NonTerminalExpression()
{
}