#include "RootExtraction.h"
RootExtraction::RootExtraction()
{
}
std::string RootExtraction::emit() // function to return the symbol of arithmetic operation
{
	return radical.getCharacter();
}

double RootExtraction::calculate(std::unique_ptr<AbstractExpression>& pRoot)
{
	double firstValue = 0;
	std::pair<double, double> secondValue = { 0,0 };

	firstValue = pRoot->getRightNode()->calculate(pRoot->getRightNode()); 
	secondValue.second = modf(pRoot->getLeftNode()->calculate(pRoot->getLeftNode()),&secondValue.first); //writing the fraction part of secondValue into a variable
	
	if ((secondValue.first>0 && secondValue.second==0) && !(firstValue < 0 && std::fmod(secondValue.first, 2) == 0)) // second value must be a natural number and we must'n make roots when the degree is even and the number is negative

	{
		if (firstValue < 0 && std::fmod(secondValue.first, 2) != 0)
			return std::negate<double>()(pow(fabs(firstValue), 1.0 / secondValue.first));
		else
			return pow(firstValue, 1.0 / secondValue.first); // firstValue <=> number we make roots, secondValue <=> specify n-th root 
	}
	else
		throw InvalidOperandException();
}

void RootExtraction::checkAST() //function to check correctness of abstract syntax tree, every node (which is non terminal expressinon) should have got two children 
{
	if (this->getLeftNode() != nullptr && this->getRightNode() != nullptr)
		return;
	else
		throw SyntaxErrorException();
}

void RootExtraction::buildAST(std::unique_ptr<AbstractExpression>& pRoot, Parser & parser) //function to build abstract syntax tree, build tree for left node and next for right node
{
	if (pRoot == nullptr)
		pRoot = std::make_unique<RootExtraction>();

	std::unique_ptr<AbstractExpression> tokenLeftObject = parser.parse();
	if (tokenLeftObject != nullptr)
		tokenLeftObject->buildAST(pRoot->getLeftNode(), parser);

	std::unique_ptr<AbstractExpression> tokenRightObject = parser.parse();
	if (tokenRightObject != nullptr)
		tokenRightObject->buildAST(pRoot->getRightNode(), parser);
	return;
}
RootExtraction::~RootExtraction()
{
}
