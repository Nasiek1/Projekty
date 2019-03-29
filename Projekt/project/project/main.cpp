#include<iostream>
#include"InputStream.h"
#include<regex>
#include<iterator>
#include<string>
#include<sstream>
#include"TokenStreamSelector.h"
#include"TokenRegex.h"
int main()
{
	try {
		InputStream is("Data.txt");
		TokenStreamSelector token(is.readData());
		token.splitIntoToken();
		
	}
	catch (IncorrectDataException& ex)
	{
		std::cout<<ex.what();
	}
	catch (FileNotFoundException& ex)
	{
		std::cout<<ex.what();
	}
	catch (std::exception& ex)
	{
		std::cout<<ex.what();
	} 
	std::cout << "okej";
	

	return 0;
	//co jezeli w pliku dane beda charami wtedy jako int potraktowane
	// co z liczbami ujemnymi, jak sa wprowadzane dane do pliku miedzy nimi spacje? tokeny sa gdzie przechowywane?
}