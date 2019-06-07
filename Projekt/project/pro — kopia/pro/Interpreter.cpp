#include "Interpreter.h"


Interpreter::Interpreter(const std::string & data) 
{
	pRoot = std::make_unique<AbstractExpression>();
	parser = Parser(data);
}
void Interpreter::interpret() //function to build abstract syntax tree
{
	if (std::unique_ptr<AbstractExpression> tmp = parser.parse()) 
	{
		pRoot = std::move(tmp);
		pRoot->buildAST(pRoot, parser);
		if (parser.getData().size() > 0)
			throw SyntaxErrorException();
	}
	else
		throw SyntaxErrorException(); // throw exception in InputStream because this fail is if the file is empty  
}
void Interpreter::checkASTCorrectness(std::unique_ptr<AbstractExpression> & root)  //function to check if the built tree is correctness with the rules of considered grammar
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
void Interpreter::emit(std::unique_ptr<AbstractExpression>& root) //function to print abstract syntax tree on screen
{
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
std::string Interpreter::determineInfixForm(std::string & infixForm, std::unique_ptr<AbstractExpression>& root, bool is_root) //function to determine infix form of expression, determination is associated with pass through absract syntax tree in order
{
	if (root)
	{
		bool show_parenthesis = (root->getLeftNode() || root->getRightNode()) && !is_root;

		if (show_parenthesis)
			infixForm += "(";

		determineInfixForm(infixForm, root->getLeftNode(), false);
		infixForm += root->emit();
		determineInfixForm(infixForm, root->getRightNode(), false);

		if (show_parenthesis)
			infixForm += ")";
	}
	return infixForm;
}
double Interpreter::calculate(std::unique_ptr<AbstractExpression>& root) //function to calculate the whole result (value) of all arithmetic operations in expression
{
	if (root == nullptr)
		return 0.0;
	else
		return root->calculate(root);
}
Interpreter::~Interpreter()
{
}
