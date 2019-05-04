#include<iostream>
#include"InputStream.h"
#include<regex>
#include<iterator>
#include<string>
#include<sstream>
#include"Lexer.h"
#include"TokenRegex.h"
#include"Parser.h"
#include"Token.h"
#include"Interpreter.h"
#include"AbstractExpression.h"
//void daj_glos(AbstractExpression & expr)
//{
//	
//	expr.buildAST(tmp);
//}
void build()
{
	Parser p=Parser();

	//while (p.parse())
	//{
	//	p.parse()->buildAST();// (p.parse());
	//} //nie dziala!!!
	
		//daj_glos(p.parse());
	//while (p.parse())
	{
		//std::unique_ptr<AbstractExpression> tmp(p.parse()->clone());
		//p.parse()->buildAST(std::unique_ptr<AbstractExpression> & pRoot);
	}
}

int main()
{

	try {
		//InputStream is("Data.txt");
		//Lexer token(is.readData());
		//token.getToken();
		//
		//std::unique_ptr<Number<int>> add= std::make_unique<Number<int>>();
		////daj_glos(*add);//DZIALA!!! JUHU
		////std::unique_ptr<Number<int>> add = std::make_unique<Number<int>>();

		////build();
		///*Addition* add = new Addition();
		//daj_glos(*add);*/ //DZIALA
		//
		//std::unique_ptr<Number<int>> liczba= std::make_unique<Number<int>>();
		////liczba->buildAST();
		//AbstractExpression expr;
		
		Interpreter interpret;
		interpret.interpret();
		
	
		
	}
	catch (IncorrectDataException& ex)
	{
		std::cout << ex.what();
	}
	catch (FileNotFoundException& ex)
	{
		std::cout << ex.what();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
	std::cout << "okej";




	return 0;
//co jezeli w pliku dane beda charami wtedy jako int potraktowane
// co z liczbami ujemnymi, jak sa wprowadzane dane do pliku miedzy nimi spacje? tokeny sa gdzie przechowywane?
}