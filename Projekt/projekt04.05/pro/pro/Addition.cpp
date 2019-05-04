#include "Addition.h"
#include"Parser.h"
Addition::Addition()
{
}

Addition::Addition(const std::string & newData)
	:NonTerminalExpression(newData)
{
}

void Addition::buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData) // nie mozemy tylko na niterminalu bo musimy dodac do drzewa obiekt okreslonej klasy a przez this nie mozna 
//wiec musimy skopiowac go dodac wiec musi byc to nie w nonterminal ale w okreslonej klasie
{
	//pRoot->setLeftNode(*&this->parser->parse());
	if (pRoot == nullptr)
		pRoot = std::make_unique<Addition>(newData);

	std::unique_ptr<AbstractExpression> tmp= pRoot->getToken();

	tmp->getParser()->setData(pRoot->getParser()->getData());
	newData = tmp->getParser()->getData();
	//this->getParser()->setData(pRoot->getParser()->getData());
	tmp->buildAST(pRoot->getLeftNode(),newData); //zmienic wartosc lewego i prawego jak sie wywoluje

	tmp=pRoot->getToken();
	tmp->getParser()->setData(pRoot->getParser()->getData());
	newData = tmp->getParser()->getData();
	//this->getParser()->setData(pRoot->getParser()->getData());
	tmp->buildAST(pRoot->getRightNode(),newData);

	return;

}




Addition::Addition(Addition && add)
{
}

Addition::~Addition()
{
}
