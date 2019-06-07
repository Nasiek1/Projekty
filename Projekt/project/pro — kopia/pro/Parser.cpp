#include "Parser.h"

Parser::Parser()
{
}

Parser::Parser(const std::string & expression)
{
	lexer = std::make_unique<Lexer>(expression);
}
std::string Parser::getData()
{
	return lexer->getData();
}
void Parser::setData(const std::string & newData)
{
	lexer->setData(newData);
}
std::unique_ptr<AbstractExpression> Parser::parse() //function to create object appropriate class which depend on taken token and it's type, value
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
				return std::make_unique<Addition>(); 
			}
			case MINUS:
			{
				return std::make_unique<Subtraction>();
			}
			case ASTERISK:
			{
				return std::make_unique<Multiplication>();
			}
			case SLASH:
			{
				return std::make_unique<Division>();
			}
			case POWER:
			{
				return std::make_unique<Exponentiation>();
			}
			case RADICAL:
			{
				return std::make_unique<RootExtraction>();
			}
			case MAX:
			{
				return std::make_unique<Maximum>();
			}
			case MIN:
			{
				return std::make_unique<Minimum>();
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

				return std::make_unique<Number <int> >(std::get<int>(currentToken.value));

			else if (currentToken.value.index() == 1)

				return std::make_unique<Number <double> >(std::get<double>(currentToken.value));
		}
	}
	return nullptr;
}
Parser::~Parser()
{
}
