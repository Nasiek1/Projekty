#pragma once
#include"Interpreter.h"
#include<memory>
class AnalyzerLL
{
	std::unique_ptr<Interpreter> interpreter;
public:
	AnalyzerLL(const std::string & expression);
	void emitAnalysisLL();
	void interpret();
	double calculate();
	std::string determineInfixForm();
	~AnalyzerLL();
};

