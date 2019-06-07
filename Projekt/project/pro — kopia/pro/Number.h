#pragma once
#include<iostream>
#include<vector>
#include<typeinfo>
#include"TerminalExpression.h"
template<typename T>
class Number :public TerminalExpression
{
	T value; 
public:
	Number();
	Number(const T & val);
	std::string emit();
	Number(const std::string & newData,const T & val);
	bool operator==(const Number<T>& figure);
	void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser & parser);
	T getValue();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	Number<T> operator+(const Number<T>& number);
	Number<T>& operator=(Number<T>&& figure);
	~Number();

};
template<typename T>
std::string Number <T>::emit() //function to return number's value
{
	return std::to_string(this->getValue()); 
}
template<typename T>
Number <T>::Number()
{

}
template<typename T>
bool Number<T>::operator==(const Number<T>& figure)
{
	return value == figure.value;
}
template<typename T>
inline void Number<T>::checkAST() //function to check correctness of abstract syntax tree, every node (which is terminal expression) shouldn't have got any children
{
	return;
}
template<typename T>
void Number<T>::buildAST(std::unique_ptr<AbstractExpression> & pRoot, Parser & parser) //function to build abstract syntax tree for number (add new node to building tree)
{
	if (pRoot == nullptr)
		pRoot = std::make_unique<Number<T>>(this->getValue());
	return;
}
template<typename T>
Number<T>::Number(const T & val)
	:value(val)
{

}
template<typename T>
inline Number<T>::Number(const std::string & newData, const T & val)
	:TerminalExpression(newData),
	value(val)
{
}
template<typename T>
Number<T>::~Number()
{

}

template<typename T>
T Number<T>::getValue()
{
	return value;
}

template<typename T>
inline double Number<T>::calculate(std::unique_ptr<AbstractExpression>& pRoot) //function to calculate the value of expression              
{
	return this->getValue();
}

template<typename T>
inline Number<T> Number<T>::operator+(const Number<T>& number)
{
	return Number<T>(this->getValue() + number.getValue());
}

template<typename T>
inline Number<T>& Number<T>::operator=(Number<T>&& figure)
{
	if(*this!=figure)
	value = figure.value;

	return *this;
}
