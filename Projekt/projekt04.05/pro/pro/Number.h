#pragma once
#include<iostream>
#include<typeinfo>
#include"TerminalExpression.h"
template<typename T>
class Number :public TerminalExpression
{
	T value;
protected:
	//virtual Number<T>* clone_impl() const override { return new Number<T>(); };
public:
	Number();
	/*virtual std::unique_ptr<TerminalExpression> clone() const override
	{
		return std::make_unique<Number<T>>(*this);
	}*/
	Number(const T & val);
	Number(const std::string & newData,const T & val);
	bool operator==(const Number<T>& figure);
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData);
	T getValue();
	Number<T>& operator=(Number<T>&& figure);
	~Number();

};
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
void Number<T>::buildAST( std::unique_ptr<AbstractExpression> & pRoot, std::string & newData)
{
	if (pRoot == nullptr)
		pRoot = std::make_unique<Number<T>>(newData,this->getValue());
	newData = this->getParser()->getData();
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
inline Number<T>& Number<T>::operator=(Number<T>&& figure)
{
	if(*this!=figure)
	value = figure.value;

	return *this;
}
