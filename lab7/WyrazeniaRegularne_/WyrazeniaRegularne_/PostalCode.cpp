#include "PostalCode.h"

void postalCode::readFile()
{
	std::ifstream PlikWej(fileName);
	if (PlikWej)
	{
		std::string linia;
		while(std::getline(PlikWej, linia))
		{
			std::smatch wynik;
			std::regex zasada("\\d{2}-\\d{3} ");
			
			while (std::regex_search(linia, wynik,zasada))
			{
				codesArr.push_back(wynik.str());
				linia = wynik.suffix();
			}
	}
		PlikWej.close();
	}
}

std::size_t postalCode::codeAmount()
{
	return codesArr.size();
}

postalCode::postalCode(std::string _fileName)
	:fileName(_fileName)
{
}

void postalCode::printCodes()
{
	for (int i = 0; i < codesArr.size(); i++)
		std::cout << codesArr[i] << "\n";
}
