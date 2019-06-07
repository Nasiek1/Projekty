#include "Maximum.h"

Maximum::Maximum()
{
}

std::string Maximum::emit() // function to return the symbol of arithmetic operation
{
	return max.getCharacter();
}

double Maximum::calculate(std::unique_ptr<AbstractExpression>& pRoot) //function to calculate the value of expression, determine each value of daughter node and specify maximum from them 
{
	double firstValue = 0;
	double secondValue = 0;

	firstValue = pRoot->getLeftNode()->calculate(pRoot->getLeftNode());
	secondValue = pRoot->getRightNode()->calculate(pRoot->getRightNode());

	return std::fmax(firstValue,secondValue);
}


void Maximum::checkAST() //function to check correctness of abstract syntax tree, every node (which is non terminal expressinon) should have got two children 
{
	if (this->getLeftNode() != nullptr && this->getRightNode() != nullptr)
		return;
	else
		throw SyntaxErrorException();
}

void Maximum::buildAST(std::unique_ptr<AbstractExpression>& pRoot, Parser & parser) //function to build abstract syntax tree, build tree for left node and next for right node
{
	if (pRoot == nullptr)
		pRoot = std::make_unique<Maximum>();

	std::unique_ptr<AbstractExpression> tokenLeftObject = parser.parse();
	if (tokenLeftObject != nullptr)
		tokenLeftObject->buildAST(pRoot->getLeftNode(), parser);

	std::unique_ptr<AbstractExpression> tokenRightObject = parser.parse();
	if (tokenRightObject != nullptr)
		tokenRightObject->buildAST(pRoot->getRightNode(), parser);
	return;

}
Maximum::~Maximum()
{
}
