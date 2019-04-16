#include "Token.h"
Token::Token(const std::string& information)
	:data(information)
{
}
//std::unique_ptr<AbstractExpression> TokenStreamSelector::createTerminalOperator(const std::string &expression)
//{
//	if (std::regex_match(expression, pattern.getPlus()))
//		return std::make_unique<AbstractExpression>(new Plus());
//	else
//		return nullptr;
//}
//std::unique_ptr<AbstractExpression> TokenStreamSelector::createTerminalNumber(const std::string& expression)
//{
//	//klasa 
//	//wartosc string 
//	//typ: enum[int, double, operator]
//
//	std::smatch patternResult;
//	if (std::regex_match(expression, patternResult, pattern.getNumber()))
//		return std::make_unique<AbstractExpression>(new Number<double>(std::stod(patternResult[0].str()));
//	else
//		return std::make_unique<AbstractExpression>(new Number<int>(std::stoi(patternResult[0].str().c_str())));
//}
/*std::vector<std::unique_ptr<AbstractExpression>>*/void TokenStreamSelector::splitIntoToken()
{
	std::vector <std::unique_ptr<AbstractExpression>> tokenVector{};//dane zwalidowane
	while (data.size() > 0)
	{
		std::size_t found = data.find(" ");
		std::string singleToken = {};
		if (found != std::string::npos)
			singleToken = data.substr(0, found);
		else
			singleToken = data.substr(0, data.size());
		if (pattern.isTerminalOperator(singleToken)){}
		//tokenVector.push_back(std::move(createTerminalOperator(singleToken)));
		else if (pattern.isTerminalNumber(singleToken))
			//tokenVector.push_back(std::move(createTerminalNumber(singleToken)));
			data.erase(0, singleToken.size()+1); //wlacznie ze spacja
	}
	//return std::move(tokenVector);
}
TokenStreamSelector::~TokenStreamSelector()
{
}
