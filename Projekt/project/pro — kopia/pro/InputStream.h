#pragma once
#include<string>
#include<fstream>
#include<exception>
#include<regex>
#include<istream>
#include<vector>
#include"IncorrectDataException.h"
#include"FileNotFoundException.h"
class InputStream
{
	std::string nameFile;
public:
	InputStream();
	InputStream(const std::string& name);
	std::vector<std::string> readData();
	bool validate(const std::string& data);
	~InputStream();
};

