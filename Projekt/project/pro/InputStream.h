#pragma once
#include<string>
#include<fstream>
#include<exception>
#include<regex>
#include<istream>
#include"IncorrectDataException.h"
#include"FileNotFoundException.h"
class InputStream
{

	std::string nameFile;
public:
	InputStream(const std::string& name);
	std::string readData();
	bool validate(const std::string& data);
	InputStream();
	~InputStream();
};

