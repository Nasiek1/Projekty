#include "Lexer.h"
Lexer::Lexer(const std::string& information)
{
	std::unique_ptr<InputStream> ins = std::make_unique<InputStream>();
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
token Lexer::getToken() // function to cut expression on single part and create on this basis appropriate tokens
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
