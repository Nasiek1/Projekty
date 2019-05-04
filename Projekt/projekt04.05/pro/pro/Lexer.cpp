#include "Lexer.h"
Lexer::Lexer()
{
	std::unique_ptr<InputStream> ins = std::make_unique<InputStream>("Data.txt");
	data = std::move(ins->readData());
	std::cout << "Lexer\n";
}
Lexer::Lexer(const std::string& information)
	:data(information)
{
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
	//std::smatch matchResult;
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
	std::cout << "Des L\n";
}
