#pragma once
#include<exception>
class IncorrectDataException : public std::exception
{

public:
	const char* what() const noexcept;
	IncorrectDataException();
	~IncorrectDataException();
};

