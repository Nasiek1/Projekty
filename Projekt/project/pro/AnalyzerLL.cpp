#include "AnalyzerLL.h"



AnalyzerLL::AnalyzerLL()
{
	interpreter = std::make_unique<Interpreter>();
}

AnalyzerLL::AnalyzerLL(const std::string & expression)
{
	interpreter = std::make_unique<Interpreter>(expression);
}

void AnalyzerLL::emitAnalysisLL()
{
	interpreter->interpret();
	interpreter->emit(interpreter->getpRoot());
}

double AnalyzerLL::calculate()
{
	interpreter->interpret();
	return interpreter->calculate(interpreter->getpRoot());
}


AnalyzerLL::~AnalyzerLL()
{
}
