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
#include<cmath>
#include"Simulator.h"
//#define new new(_NORMAL_BLOCK,_FILE_,_LINE_)
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try
	{
		if (argc != 2)
		{
			std::cout << "Incorrect data, the program was run with default parameters\n";
			Simulator simulator = Simulator();
			simulator.runSimulation();
		}
		else
		{
			std::string nameFile = argv[1];
			Simulator simulator(nameFile);
			simulator.runSimulation();
		}
	}
		catch (IncorrectDataException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (FileNotFoundException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (InvalidArgumentException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (InvalidOperandException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (SyntaxErrorException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		_CrtDumpMemoryLeaks();
		return 0;
	}