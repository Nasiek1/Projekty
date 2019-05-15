#pragma once
#include"Interpreter.h"
#include<memory>
class AnalyzerLL
{
	std::unique_ptr<Interpreter> interpreter;
public:
	AnalyzerLL();
	AnalyzerLL(const std::string & expression);
	void emitAnalysisLL();
	double calculate();
	~AnalyzerLL();
};

