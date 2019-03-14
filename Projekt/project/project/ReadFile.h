#pragma once
#include"InterpreterNP.h"
#include"Interpreter.h"
#include"InterpreterONP.h"
#include<string>
#include<fstream>
#include<exception>
#include<regex>
class ReadFile
{
	std::string nameFile;
public:
	ReadFile(const std::string& name);
	ReadFile();
	void readFile();
	~ReadFile();
};

