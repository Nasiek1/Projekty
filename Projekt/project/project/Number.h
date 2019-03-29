#pragma once
#include<iostream>
#include<typeinfo>
#include"AbstractExpression.h"
#include"TerminalExpression.h"
template<typename T>
class Number:public TerminalExpression
{ 
	T value;
public:
	Number();
	Number(const T & val);
	Number(const Number<T>& copy);
	bool operator==(const Number<T>& figure);
	Number<T>& operator=(Number<T>&& figure); //przypisywac i przenosic wynik z jednej liczby drugiej
	~Number();
};
