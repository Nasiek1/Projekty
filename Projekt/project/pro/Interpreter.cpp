#include "Interpreter.h"



Interpreter::Interpreter()
{
	pRoot = std::make_unique<AbstractExpression>();
	parser = std::make_unique<Parser>();
}

Interpreter::Interpreter(const std::string & data)
{
	pRoot = std::make_unique<AbstractExpression>();
	parser = std::make_unique<Parser>(data);
}

void Interpreter::interpret()
{
	std::vector<std::unique_ptr<AbstractExpression>> vectorAbstractExpr;
	std::unique_ptr<AbstractExpression> tmp = parser->parse(); //czy zwracac jeden token czy wektor????
	while (tmp)
	{
		vectorAbstractExpr.push_back(std::move(tmp));
		tmp = parser->parse();

	}
	if (vectorAbstractExpr.size() > 0)
	{
		pRoot = std::move(vectorAbstractExpr[0]);
		vectorAbstractExpr.erase(vectorAbstractExpr.begin());
		pRoot->buildAST(pRoot, vectorAbstractExpr);
	}
	else
		throw SyntaxErrorException();
}
void Interpreter::checkASTCorrectness(std::unique_ptr<AbstractExpression> & root) //czy w porzadku?
{
	if (root == nullptr)
		return;

		root->checkAST();
		checkASTCorrectness(root->getLeftNode());
		checkASTCorrectness(root->getRightNode());
}
std::unique_ptr<AbstractExpression>& Interpreter::getpRoot()
{
	return pRoot;
}
void Interpreter::emit(std::unique_ptr<AbstractExpression>& root)
{
	checkASTCorrectness(root);

	if (root)
	{
		
		bool show_parenthesis = root->getLeftNode() || root->getRightNode();

		if (show_parenthesis) std::cout << '(';

		emit(root->getLeftNode());
		std::cout << root->emit();
		emit(root->getRightNode());

		if (show_parenthesis) std::cout << ')';
	}
}
double Interpreter::calculate(std::unique_ptr<AbstractExpression>& root)
{
	if (root == nullptr)
		return 0.0;
	else
		return root->calculate(root);
}
Interpreter::~Interpreter()
{
}
