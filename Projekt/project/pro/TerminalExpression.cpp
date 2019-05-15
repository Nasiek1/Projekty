#include "TerminalExpression.h"

void TerminalExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr)
{
	
}

TerminalExpression::TerminalExpression()
{
}
std::string TerminalExpression::emit()
{
	return 0;
}
void TerminalExpression::checkAST()
{
}
double TerminalExpression::calcuate(std::unique_ptr<AbstractExpression>& pRoot)
{
	return 0.0;
}
TerminalExpression::~TerminalExpression()
{
}
