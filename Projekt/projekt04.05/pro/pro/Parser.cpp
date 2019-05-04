#include "Parser.h"


Parser::Parser()
{
	lexer = std::make_unique<Lexer>();
	std::cout << "Parser\n";
	
}
std::string Parser::getData()
{
	return lexer->getData();
}
void Parser::setData(const std::string & newData)
{
	lexer->setData(newData);
}
std::unique_ptr<AbstractExpression> Parser::parse()
{

	currentToken = lexer->getToken();
	if (currentToken != EOS)
	{
		if (currentToken.type != NUMBER)
		{
			switch (currentToken.type)
			{
			case PLUS:
			{
				return std::make_unique<Addition>(lexer->getData()); //przypisac aby nowy obiekt mial linie ta po pocieciu
				//lepiej niz sprawdzac kazy mozliwy operator a tutaj tylko moze byc number lub operator
			}
			default: //if(currentToken.type == NUMBER)
			{
				throw IncorrectDataException();
			}
			}

		}
		else
		{
			if (currentToken.value.index() == 0)

				return std::make_unique<Number <int> >(lexer->getData(),std::get<int>(currentToken.value));

			else if (currentToken.value.index() == 1)

				return std::make_unique<Number <double> >(lexer->getData(),std::get<double>(currentToken.value));
		}
	}
	return nullptr;
}
Parser::~Parser()
{
	std::cout << "Des P\n";
}

//Parser::Parser(const AbstractExpression & expr)
//	:pointer(expr.clone())
//{
//}

Parser::Parser(const Parser & other)
	//:pointer(other.pointer->clone())
{
}

Parser & Parser::operator=(const Parser & other)
{
	//pointer=other.pointer->clone();
	return *this;
}

