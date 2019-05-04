#pragma once
#include<exception>
class InvalidArgumentException : public std::exception
{
public:
	const char* what() const noexcept;
	InvalidArgumentException();
	~InvalidArgumentException();
};

