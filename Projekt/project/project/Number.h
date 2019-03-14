#pragma once
#include<iostream>
#include<typeinfo>
#include"TerminalExpression.h"

template<typename T>
class Number:public TerminalExpression
{ 
	T value;
public:
	Number();
	Number(const T & val);
	Number(const Number<T>& copy);
	Number& operator=(Number&& figure); //przypisywac i przenosic wynik z jednej liczby drugiej
	~Number();
};
