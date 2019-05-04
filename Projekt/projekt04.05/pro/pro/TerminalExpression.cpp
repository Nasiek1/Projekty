#include "TerminalExpression.h"

void TerminalExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData)
{
	
}

TerminalExpression::TerminalExpression()
{
}

TerminalExpression::TerminalExpression(const std::string & newData)
	:AbstractExpression(newData)
{
}

//TerminalExpression::operator==(const TerminalExpression& terminalExp)
//{
//
//}

TerminalExpression::~TerminalExpression()
{
}
