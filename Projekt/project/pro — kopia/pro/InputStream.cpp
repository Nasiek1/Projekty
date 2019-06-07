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
	std::regex pattern("[^.+^*-/0-9 n\t\r\n root max min]"); // the permissible set of characters is negated by using '^' at the very beginning of pattern; as a result we check whether the expression contains 
	//characters other than numbers, operators and white space
	return !std::regex_search(data, pattern); //we assume that function return true if the expression contains only acceptable symbols	
	//if regex_search() find matching - return true, it means that in expressions are unacceptable symbols so we have to negate return value										
}
std::vector<std::string> InputStream::readData() //function to read data (expressions) from file- line by line and validate them
{
	std::vector<std::string> expressions;
	std::ifstream ifs(nameFile);
	if (ifs)
	{
		std::string line;
		while (std::getline(ifs, line))
		{
			if (validate(line)) {

				expressions.push_back(line);
			}
			else {
				ifs.close();
				throw IncorrectDataException();
			}
		}
		ifs.close();
		return expressions;
	}
	throw FileNotFoundException();
}
InputStream::~InputStream()
{
}
