#include "AbstractExpression.h"
AbstractExpression::AbstractExpression()
	:leftNode(nullptr),
	rightNode(nullptr)
{
}

double AbstractExpression::calculate(std::unique_ptr<AbstractExpression>& pRoot)
{
	return 0.0;
}



void AbstractExpression::setLeftNode(std::unique_ptr<AbstractExpression>& pLeft)
{
	this->leftNode = std::move(pLeft);
}

void AbstractExpression::setRightNode(std::unique_ptr<AbstractExpression>& pRight)
{
	this->rightNode = std::move(pRight);
}

AbstractExpression & AbstractExpression::operator=(AbstractExpression && expr)
{
	if (this != &expr)
	{
		std::swap(leftNode, expr.leftNode);
		std::swap(rightNode, expr.rightNode);
	}
	return *this;
}

void AbstractExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr)
{
	
	
}
AbstractExpression::~AbstractExpression()
{
}

std::string AbstractExpression::emit()
{
	return 0;
}
std::unique_ptr<AbstractExpression>& AbstractExpression::getLeftNode()
{
	return leftNode;
}

std::unique_ptr<AbstractExpression>& AbstractExpression::getRightNode()
{
	return rightNode;
}

void AbstractExpression::checkAST()
{
}
