#include "AnalyzerLL.h"

AnalyzerLL::AnalyzerLL(const std::string & expression)
{
	interpreter = std::make_unique<Interpreter>(expression);
}
void AnalyzerLL::interpret() // function to build the whole abstract syntax tree and check if it's correct 
{
	interpreter->interpret();
	interpreter->checkASTCorrectness(interpreter->getpRoot());
}
void AnalyzerLL::emitAnalysisLL() // function to print abstract syntax tree on screen
{
	interpreter->emit(interpreter->getpRoot());
}

double AnalyzerLL::calculate()
{
	return interpreter->calculate(interpreter->getpRoot());
}
std::string AnalyzerLL::determineInfixForm() // function to determine infix form based on abstract syntax tree
{
	std::string infixForm{};
	return interpreter->determineInfixForm(infixForm,interpreter->getpRoot(),true);
}

AnalyzerLL::~AnalyzerLL()
{
}
