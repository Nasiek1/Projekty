#include "InputStream.h"
#include<iostream>
InputStream::InputStream()
{

}
InputStream::InputStream(const std::string& name)
	:nameFile(name)
{
	std::cout << "input\n";
}
bool InputStream::validate(const std::string &data)
{
	if (data.size() == 0) {
		return false;
	}
	std::regex pattern("[^.+*-/0-9 n\t\r\n]");//sprawdzic czy dziala tez:"[^.+*-\\d \t\r\n]");
	return !std::regex_search(data, pattern); //znalazl litery zwraca true wiec musi byc negacja
}
std::string InputStream::readData()
{
	std::ifstream ifs(nameFile);
	if (ifs)
	{
		std::string line;
		while (std::getline(ifs, line))
		{
			if (validate(line))
				return line;
		}
		throw IncorrectDataException();
		ifs.close();
	}
	throw FileNotFoundException();
}
InputStream::~InputStream()
{
}
