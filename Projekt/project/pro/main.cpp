#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include"InputStream.h"
#include<regex>
#include <stdlib.h>
#include <crtdbg.h>
#include<iterator>
#include<string>
#include<sstream>
#include"Lexer.h"
#include"TokenRegex.h"
#include"Parser.h"
#include"Token.h"
#include"Interpreter.h"
#include"AbstractExpression.h"
#include"AnalyzerLL.h"
#include<thread>
#include <vld.h>
//#define new new(_NORMAL_BLOCK,_FILE_,_LINE_)
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try {
		
		//Interpreter interpret("+ 3 + 1 2");
		//interpret.calculate();
		//Interpreter interpret("+ + + 2 3 5 + 4 9");
		//Interpreter interpret("+ + + + 2 3 5 4 9");
		//Interpreter interpret("+ + 2.0909 3 + 4 9");
		//Interpreter interpret("+ + 2 + 5 4 9"); //jedna spacja oddzielone zaczynaja sie nie od spacji i koncza nie od spacji
		//Interpreter interpret("+ + 3 4 + 2");
		//AnalyzerLL a("+ + 2 + 5 4 9"); 
		//AnalyzerLL a("+ + + 2 3 5 + 4 9");
		//AnalyzerLL a("+ + 2 3 + 1");
		//a.emitAnalysisLL();
		AnalyzerLL analizer("+ + 2.0909 3 + 4 9");

		std::chrono::high_resolution_clock::time_point time1 = std::chrono::high_resolution_clock::now();

		std::cout<<analizer.calculate();

		std::chrono::high_resolution_clock::time_point time2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = time2 - time1;
		std::cout << "To zajelo: " << time_span.count() << " sekund" << "\n";
		
	//jak zrobic sprawdzenie czy drzewo poprawne juz przy budowaniu?
		
	}
	catch (IncorrectDataException& ex)
	{
		std::cout << ex.what();
	}
	catch (FileNotFoundException& ex)
	{
		std::cout << ex.what();
	}
	catch (SyntaxErrorException& ex)
	{
		std::cout << ex.what();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}