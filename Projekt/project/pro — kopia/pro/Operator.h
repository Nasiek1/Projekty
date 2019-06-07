#pragma once
#include<iostream>
#include<memory>
#include"TerminalExpression.h"
class Operator : public TerminalExpression
{
protected:
	std::string character; 
public:
	Operator();
	Operator(const std::string& sign); 
	bool operator==(const Operator& operat);
	std::string getCharacter();
	void setCharacter(const std::string & sign);
	~Operator();
};
