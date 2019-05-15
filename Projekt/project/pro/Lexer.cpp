#include "Lexer.h"
Lexer::Lexer()
{
	std::unique_ptr<InputStream> ins = std::make_unique<InputStream>("Data.txt");
	data = ins->readData();

}
Lexer::Lexer(const std::string& information)
{
	//jezeli ktos poda rozszerzenie .txt to wtedy czytamy z pliku w przeciwnym wypadku z cout 
	std::string isTxt = information.substr(information.size() - 4, 4);
	if(isTxt.find(".txt") != std::string::npos)
	{
		std::unique_ptr<InputStream> ins = std::make_unique<InputStream>(information);
		data = std::move(ins->readData());
	}
	else
		data = information;
}
std::string Lexer::getData()
{
	return data;
}
void Lexer::setData(const std::string & newData)
{
	data = newData;
}
token Lexer::getToken()
{
	if (data.size() == 0)
	{
		return token{ EOS };
	}

	token singleT;
	int idxFound = data.find(" ");
	std::string singleString = data.substr(0, idxFound);

	if (pattern.isTerminalOperator(singleString))
		singleT = pattern.checkTypeOperator(singleString);

	else if (pattern.isTerminalNumber(singleString))
		singleT = pattern.checkTypeNumber(singleString);

	if (idxFound != std::string::npos)
		data.erase(0, idxFound + 1);
	else
		data.clear();

	return singleT;



}
Lexer::~Lexer()
{
}
