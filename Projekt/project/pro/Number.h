#pragma once
#include<iostream>
#include<vector>
#include<typeinfo>
#include"TerminalExpression.h"
template<typename T>
class Number :public TerminalExpression
{
	T value; //czy konwertowac wartosc czy zrobic drugie pole z wartoscia string?
public:
	Number();
	Number(const T & val);
	std::string emit();
	Number(const std::string & newData,const T & val);
	bool operator==(const Number<T>& figure);
	void checkAST();
	void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr);
	T getValue();
	double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	Number<T> operator+(const Number<T>& number);
	Number<T>& operator=(Number<T>&& figure);
	~Number();

};
template<typename T>
std::string Number <T>::emit()
{
	return std::to_string(this->getValue()); //???????? okej?
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
inline void Number<T>::checkAST()
{
	return; //nic nie robimy jak liczba to wszystko w porzadku
}
template<typename T>
void Number<T>::buildAST( std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr)
{
	if (pRoot == nullptr && vectorExpr.size()>0)
	{
		pRoot=std::make_unique<Number<T>>(this->getValue());
		vectorExpr.erase(vectorExpr.begin());
	}
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
inline double Number<T>::calculate(std::unique_ptr<AbstractExpression>& pRoot)
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
