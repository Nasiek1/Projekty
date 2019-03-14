#include "ReadFile.h"
ReadFile::ReadFile()
{
}
ReadFile::ReadFile(const std::string& name)
	:nameFile(name)
{

}
ReadFile::~ReadFile()
{
}
void ReadFile::readFile()
{
	std::ifstream InputFile(nameFile);
	if (InputFile)
	{
		std::string notationONP = "ONP"; //assigment operator nie rozroznia wielkosci liter wiec w porzadku
		//std::string notationNP = "NP"; nie trzeba bo albo jedno aldo drugie dopasowanie
		std::string line;
		std::regex pattern("(int)|(float)|(double).+([O ]NP)"); //WYSZUKUJE ALE ZAPISUJE JEDNA CZESC?!
		std::smatch patternResult;
		if (std::getline(InputFile, line))
		{
			if (std::regex_search(line,patternResult,pattern)) //jak znajde dopasowanie to albo onp albo np 
			{
				if (patternResult.str(2)==notationONP)
				{
					//patternResult.str(1) przekazuje jako typ danych ktory bedzie w szablonie
					//interpretONP();
				}
				else //wywoluje funkcje dla interpretera NP
				{
					//interpretNP();
				}
			}
			else
			{
				std::string exception = "Unknown notation or data type";
				throw exception;
			}
		}
		else
		{
			std::string exception = "Empty file";
			throw exception;
		}
		InputFile.close();
	}
	else
	{
		std::string exception = "Error with open file";
		throw exception;
	}
}