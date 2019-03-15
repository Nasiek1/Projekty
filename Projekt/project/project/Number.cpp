#include "Number.h"
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
Number<T>::Number(const int& prior,const T & val)
	:TerminalExpression(prior),value(val)
{
	
}
////operator przypisania bo bedziemy jednej liczbie przypisywac druga operator przenoszacy 
template<typename T>
Number<T>::Number(const Number<T> & copy)
	:value(copy.value)
{

}
template<typename T>
Number<T>& Number<T>::operator=(Number<T>&& figure)
{
	value = figure.value;
}
template<typename T>
Number<T>::~Number()
{

}

