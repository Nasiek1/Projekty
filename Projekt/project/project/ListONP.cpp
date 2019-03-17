#include "ListONP.h"


void ListONP::insertElement(std::unique_ptr<TerminalExpression> terminalExp)
{
	

}
void ListONP::deleteElement(std::unique_ptr<TerminalExpression> terminalExp)
{
	

}
std::unique_ptr<TerminalExpression> ListONP::getElement()
{
	std::list<std::unique_ptr<TerminalExpression>>::iterator findIter = std::find(terminalExpList.begin(), terminalExpList.end(), terminalExp);
	//if (findIter != terminalExpList.end())
		return findIter.operator*;
}
ListONP::ListONP()
{
}
ListONP::~ListONP()
{
	terminalExpList.clear();
}
