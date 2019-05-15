#pragma once
#include<exception>
class SyntaxErrorException: public std::exception
{
public:
	const char* what() const noexcept;
	SyntaxErrorException();
	~SyntaxErrorException();
};

