#include "InputStream.h"
#include<iostream>
InputStream::InputStream()
{

}
InputStream::InputStream(const std::string& name)
	:nameFile(name)
{

}
bool InputStream::validate(const std::string &data)
{
	if (data.size() == 0) {
		return false;
	}
	//std::regex pattern("[^.+*\-\/\^\s\d]");
	std::regex pattern("[a-zA-Z]|[\"\r!\\@$%&#()~= ?><,{}\]\[|_:;']"); //co z tabulacja? moze byc wykryta
	
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
