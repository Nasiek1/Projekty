#include "AbstractExpression.h"
#include "Parser.h"
AbstractExpression::AbstractExpression()
	:leftNode(nullptr),
	rightNode(nullptr)
{
	parser = std::make_unique<Parser>();
}

AbstractExpression::AbstractExpression(const std::string & newData)
		:leftNode(nullptr),
		rightNode(nullptr)
	{
	parser = std::make_unique<Parser>();
			parser->setData(newData);
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

std::unique_ptr<AbstractExpression> AbstractExpression::getToken()
{
	return parser->parse();
}

std::unique_ptr<Parser>& AbstractExpression::getParser()
{
	return parser;
}

void AbstractExpression::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData)
{
	
	
}
AbstractExpression::~AbstractExpression()
{
}


std::unique_ptr<AbstractExpression>& AbstractExpression::getLeftNode()
{
	return leftNode;
}

std::unique_ptr<AbstractExpression>& AbstractExpression::getRightNode()
{
	return rightNode;
}
