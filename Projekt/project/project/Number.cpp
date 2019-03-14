#include "Number.h"
template<typename T>
Number <T>::Number()
{

}
template<typename T> 
Number<T>::Number(const T & val)
	:value(val)
{
	
}
////operator przypisania bo bedziemy jednej liczbie przypisywac druga operator przenoszacy 
template<typename T>
Number<T>::Number(const Number<T> & copy)
	:value(copy.value)
{

}
template<typename T>
Number<T>& Number<T>::operator=(Number&& figure)
{
	value = figure.value;
}
template<typename T>
Number<T>::~Number()
{

}

