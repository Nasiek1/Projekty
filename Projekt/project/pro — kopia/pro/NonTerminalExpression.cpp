#include "NonTerminalExpression.h"
#include"Parser.h"
void NonTerminalExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr)
{

	
	
}
std::string NonTerminalExpression::emit()
{
	return 0; //co zwracac?
}
double NonTerminalExpression::calculate(std::unique_ptr<AbstractExpression>& pRoot)
{
	return 0.0;
}
void NonTerminalExpression::checkAST()
{
}
void NonTerminalExpression::buildAST(std::unique_ptr<AbstractExpression>& pRoot, Parser & parser)
{
}
NonTerminalExpression::NonTerminalExpression()
{
}

NonTerminalExpression::~NonTerminalExpression()
{
}