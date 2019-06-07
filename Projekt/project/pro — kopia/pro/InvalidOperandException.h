#pragma once
#include<exception>
class InvalidOperandException: public std::exception
{
public:
	InvalidOperandException();
	const char* what() const noexcept;
	~InvalidOperandException();
};


