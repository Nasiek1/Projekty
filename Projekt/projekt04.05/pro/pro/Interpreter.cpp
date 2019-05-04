#include "Interpreter.h"



Interpreter::Interpreter()
{
	pRoot = std::make_unique<AbstractExpression>();
}

void Interpreter::interpret()
{
	pRoot = pRoot->getToken(); //przypisujemy nowy obiekt ktory ma dane od zera 
	pRoot->buildAST(*&pRoot, *&pRoot->getParser()->getData());
	int i = 0;
}
Interpreter::~Interpreter()
{
}
