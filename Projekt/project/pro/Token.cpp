#include "Token.h"
token::token()
{

}
bool token::operator==(const token& tok)
{
	return type == tok.type;
}
bool token::operator!=(const token& tok)
{
	return type != tok.type;
}
token::token(Type type)
	:type(type)
{

}

