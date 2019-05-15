#pragma once
#include<iostream>
#include<memory>
#include"TerminalExpression.h"
class Operator : public TerminalExpression
{
protected:
	std::string character; //czy zostawic char? 
public:
	Operator();
	Operator(const std::string& sign); //czy dawac tu emita?
	bool operator==(const Operator& operat);
	std::string getCharacter();
	void setCharacter(const std::string & sign);
	~Operator();
};
