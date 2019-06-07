#include "Exponentiation.h"

Exponentiation::Exponentiation()
{
}

std::string Exponentiation::emit() // function to return the symbol of arithmetic operation
{
	return caret.getCharacter();
}

double Exponentiation::calculate(std::unique_ptr<AbstractExpression>& pRoot) //function to calculate the value of expression, determine each value of daughter node and rise firstValue by the power secondValue
{
	double firstValue = 0;
	double secondValue = 0;

	firstValue = pRoot->getLeftNode()->calculate(pRoot->getLeftNode());
	secondValue = pRoot->getRightNode()->calculate(pRoot->getRightNode());

		return pow(firstValue,secondValue);

}


void Exponentiation::checkAST() //function to check correctness of abstract syntax tree, every node (which is non terminal expressinon) should have got two children 
{
	if (this->getLeftNode() != nullptr && this->getRightNode() != nullptr)
		return;
	else
		throw SyntaxErrorException();
}

void Exponentiation::buildAST(std::unique_ptr<AbstractExpression>& pRoot, Parser & parser) //function to build abstract syntax tree, build tree for left node and next for right node
{
	if (pRoot == nullptr)
		pRoot = std::make_unique<Exponentiation>();

	std::unique_ptr<AbstractExpression> tokenLeftObject = parser.parse();
	if (tokenLeftObject != nullptr)
		tokenLeftObject->buildAST(pRoot->getLeftNode(), parser);

	std::unique_ptr<AbstractExpression> tokenRightObject = parser.parse();
	if (tokenRightObject != nullptr)
		tokenRightObject->buildAST(pRoot->getRightNode(), parser);
	return;

}
Exponentiation::~Exponentiation()
{
}
