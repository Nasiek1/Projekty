#include<iostream>
#include"User.h"
#include"PostalCode.h"
#pragma once
#include <string>
#define PASS 9 //Makro przechowuj¹ce iloœæ hase³ do testowania.
#define LOG 19	//Makro przechowuj¹ce iloœæ loginow do testowania.
constexpr auto POST = "postalExample.txt";
constexpr auto TEXT = "aabcc abcccaabco abccccerD9: aabc DE123quZE3456 sGE342nA9.";

std::string password[] = { "polskaCEBULA98!",
							"kochamMAME123.",
							"adamKowalski",
							"haselko21.",
							"bC1;",
							"janusziGRAZYNA25:",
							"Ga12!",
							"trzyCYTRYNY!",
							"trudneHaslo23!."
};

std::string login[] = { "123",
						"a345",
						"b696",
						"z666",
						"12",
						"7",
						"CA12345",
						"A123",
						"ZOMBIAK457890",
						"adam123",
						"a12",
						"a1234",
						"CYTRYNKA905678",
						"ADA345",
						"KORALE123456789",
						"PASSERATTI9865",
						"ADA345",
						"KORALE123456789",
						"KOKOJUMBO9099"
};

std::string student = "Studenci to specyficzna grupa mlodych pojawiajaca sie szczegolnie w wiekszych miastach. "
"Paliwem potrzebnym do dzialania organizmu studenta jest alkohol etylowy.";
void regexReplace()
{
	std::string wynik;
	std::regex zasada1("a{2}bc{1,2}");
	wynik=std::regex_replace(TEXT, zasada1, "in");
	std::regex zasada2("abc{3,}");
	wynik=std::regex_replace(wynik, zasada2, "v");
	std::regex zasada3("[[:upper:]][[:digit:]][[:punct:]]");
	wynik=std::regex_replace(wynik, zasada3, "itas");
	std::regex zasada4("[[:upper:]]{2}[[:digit:]]{3,}");
	wynik=std::regex_replace(wynik, zasada4, "a");

	std::cout << wynik << "\n";

}
void countWords()
{
	std::regex zasada("[^\\s]+");
	int iloscSlow = 0;
	auto words_begin= std::sregex_iterator(student.begin(), student.end(), zasada);
	auto words_end = std::sregex_iterator();

	std::cout << "Znalezione " << std::distance(words_begin, words_end) << " slowa:\n";

	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		std::smatch match = *i;
		std::string match_str = match.str();
		std::cout << match_str << '\n';
	}
}
int main()
{
	int ileHasel = 0;
	int ileLoginow = 0;
	User uzytkownik;
	for (int i = 0; i < PASS; i++)
	{
		if (uzytkownik.setPassword(password[i]))
			ileHasel++;
	}
	for (int i = 0; i < LOG; i++)
	{
		if (uzytkownik.setName(login[i]))
			ileLoginow++;
	}
	std::cout << "Ilosc poprawnych loginow: " << ileLoginow << "\n";
	std::cout << "Ilosc poprawnych hasel: " << ileHasel << "\n";
	std::cout << "Ilosc niepoprawnych loginow: " << LOG - ileLoginow << "\n";
	std::cout << "Ilosc niepoprawnych hasel: " << PASS - ileHasel << "\n";

		postalCode post(POST);
		post.readFile();
		std::cout << "Ilosc kodow: " << post.codeAmount() << "\n";
		post.printCodes();
		std::cout << "\n";
		regexReplace();
		countWords();
	return 0;
}