#include "Addition.h"
Addition::Addition()
{
}
//double Addition::sum(Number<T> number1, Number<T> number2)
//{
//
// }
std::string Addition::emit()
{
	return plus.getCharacter();
}

double Addition::calculate(std::unique_ptr<AbstractExpression>& pRoot)
{
	double firstValue= 0;
	double secondValue = 0;
	
	firstValue=pRoot->getLeftNode()->calculate(pRoot->getLeftNode());
	secondValue=pRoot->getRightNode()->calculate(pRoot->getRightNode());

	return firstValue + secondValue;
}


void Addition::checkAST()
{
	if (this->getLeftNode() != nullptr && this->getRightNode() != nullptr)
		return;
	else
		throw SyntaxErrorException();
}

void Addition::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr) // nie mozemy tylko na niterminalu bo musimy dodac do drzewa obiekt okreslonej klasy a przez this nie mozna 
//wiec musimy skopiowac go dodac wiec musi byc to nie w nonterminal ale w okreslonej klasie
{
	if (pRoot == nullptr && vectorExpr.size() > 0)
	{
		pRoot = std::make_unique<Addition>();
		vectorExpr.erase(vectorExpr.begin());
	}
	if (vectorExpr.size() > 0)
	{
		std::unique_ptr<AbstractExpression> tmp = std::move(vectorExpr[0]);
		tmp->buildAST(pRoot->getLeftNode(), vectorExpr);
	}
	if (vectorExpr.size() > 0)
	{
		std::unique_ptr<AbstractExpression> tmp = std::move(vectorExpr[0]);
		tmp->buildAST(pRoot->getRightNode(), vectorExpr);
	}
	return;

}




Addition::Addition(Addition && add)
{
}

Addition::~Addition()
{
}
