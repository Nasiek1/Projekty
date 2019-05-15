#include "User.h"

User::User()
	:name("Unknown"), password("Unkonown")
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(1, 1000);
	id = distribution(generator);
}
bool User::setName(std::string _name)
{
	std::regex zasada2("([[:lower:]]?[[:digit:]]{3})|([[:upper:]]{2,}[[:digit:]]{4,6})");
	
	if (std::regex_match(_name, zasada2))
	{
		name = _name;
		return true;
	}
	else
		return false;

}
bool User::setPassword(std::string _password)
{
	std::regex zasada1("[[:lower:]]+[[:upper:]]+[[:digit:]]+[[:punct:]]{1}");
	if (std::regex_match(_password, zasada1))
	{
		password = _password;
		return true;
	}
	else
		return false;

}