#pragma once
#include <string>
#include <random>
#include <regex>

class User
{
	int id;
	std::string name;
	std::string password;

public:
	User();
	bool setPassword(std::string _password); //Ustawia has³o zgodnie z wytycznymi wyra¿enia regularnego.
	bool setName(std::string _name); //Ustawia imie zgodnie z wytycznymi wyra¿enia regularnego.
	~User() = default;
};



