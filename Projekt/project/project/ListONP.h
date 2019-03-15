#pragma once
#include"TerminalExpression.h"
#include<memory>
#include<list>
#include<algorithm>
class ListONP
{
	std::list<std::unique_ptr<TerminalExpression>> terminalExpList;
public:
	void insertElement(std::unique_ptr<TerminalExpression> terminalExp);
	void deleteElement(std::unique_ptr<TerminalExpression> terminalExp);
	std::unique_ptr<TerminalExpression> getElement();
	ListONP();
	~ListONP();
};

