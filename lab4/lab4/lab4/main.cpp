#include <iostream>  
#include <string>  
#include <fstream>    
#include <algorithm>  
#include <utility>  
#include <vector>    
#include <forward_list>   
#include <set>    
#include <map> 

class INWESTOR
{
protected:
	std::string nazwisko;
public:
	INWESTOR() {};
	INWESTOR(std::string n) :nazwisko(n)
	{};
	std::string n()
	{
		return nazwisko;
	};
	virtual~INWESTOR()
	{};
};
class PORTFEL :public INWESTOR
{
	int akcje;
	int obligacje;
	int walutyNBP;
	int funduszOFE;
public:
	PORTFEL() {};
	std::vector<PORTFEL> wczytaj_inwestorow(std::string WE)
	{
		std::vector<PORTFEL> wczytaj{ 0 };
		std::ifstream plikWej(WE);
		if (plikWej)
		{
			while (plikWej >> nazwisko && plikWej >> akcje && plikWej >> obligacje && plikWej >> walutyNBP && plikWej >> funduszOFE)
				wczytaj.push_back(PORTFEL(nazwisko, akcje, obligacje, walutyNBP, funduszOFE));
			plikWej.close();
		}
		return wczytaj;
	}
	double getSuma(PORTFEL portfelik)
	{
		return portfelik.akcje + portfelik.obligacje + portfelik.walutyNBP + portfelik.funduszOFE;
	}
	std::forward_list <PORTFEL> sortuj(std::vector <PORTFEL> TAB)
	{
		for (int k = 0; k < TAB.size(); k++)
		{
			int idx_min = k; 
			double wartosc_min = getSuma(TAB[k]);
			for (int i = k; i < TAB.size(); i++)
			{
				if (getSuma(TAB[i]) < wartosc_min)
				{
						idx_min = i;
						wartosc_min = getSuma(TAB[i]);
				}
			}
			std::swap(TAB[k], TAB[idx_min]);
		}
		std::forward_list<PORTFEL> inwestorzy;
		for (int i = 0; i < TAB.size(); i++)
			inwestorzy.push_front(TAB[i]);
		return inwestorzy;

	}
	void wypisz_liste(std::forward_list<PORTFEL> LISTA)
	{
		std::forward_list<PORTFEL>::const_iterator it = LISTA.begin();
		for (it; it != LISTA.end(); it++)
			std::cout << it->nazwisko << " " << it->akcje << " " << it->obligacje << " " << it->walutyNBP << " " << it->funduszOFE << "\n";
	}
	void wypisz_liste_akcji(std::vector<PORTFEL> TAB)
	{
		std::forward_list<int> akcjeInwestorow{ 0 };
		for (int i = 0; i < TAB.size(); i++)
			akcjeInwestorow.push_front(TAB[i].akcje);
		akcjeInwestorow.sort();
		akcjeInwestorow.pop_front();
		akcjeInwestorow.reverse();

		std::forward_list<int>::const_iterator it = akcjeInwestorow.begin();
		for (it; it != akcjeInwestorow.end(); it++)
			std::cout << *it << "\n";
	}
	void wczytaj_i_znajdz(std::forward_list<PORTFEL> LISTA, std::string klucz)
	{
		std::set<std::string> nazwiskaInwestorow;
		std::forward_list<PORTFEL>::const_iterator iterator;
		for (iterator = LISTA.begin(); iterator != LISTA.end(); iterator++)
		{
			nazwiskaInwestorow.insert(iterator->nazwisko);
		}
		std::set<std::string>::const_iterator it = nazwiskaInwestorow.find(klucz);
		if (it != nazwiskaInwestorow.end())
			std::cout << "Znalazlem! " << klucz << "\n";
		else
			std::cout << "Nie znalazlem! " << "\n";

		for (it = nazwiskaInwestorow.begin(); it != nazwiskaInwestorow.end(); it++)
			std::cout << *it << "\n";
	}
	void przedzial(std::forward_list<PORTFEL> LISTA, const int klucz)
	{
		std::multimap<int, std::string> obligacjeInwestorow;
		std::forward_list<PORTFEL>::const_iterator iterator;
		for (iterator = LISTA.begin(); iterator != LISTA.end(); iterator++)
			obligacjeInwestorow.emplace(std::make_pair(iterator->obligacje, iterator->nazwisko));
		std::pair < std::multimap<int, std::string>::const_iterator, std::multimap<int, std::string>::const_iterator> ret;
		ret = obligacjeInwestorow.equal_range(klucz);
		while (ret.first != ret.second)
		{
			std::cout << ret.first->second << "\n";
			ret.first++;
		}
	}
	PORTFEL(std::string n, int a, int o, int w, int f) :INWESTOR(n), akcje(a), obligacje(o), walutyNBP(w), funduszOFE(f)
	{};
	~PORTFEL() {};
};
int main()
{
	PORTFEL *p = new PORTFEL;
	std::string WE = "DANE.txt";
	std::vector<PORTFEL> TAB = p->wczytaj_inwestorow(WE);
	std::forward_list <PORTFEL> LISTA = p->sortuj(TAB);
	std::cout << "\nZADANIE 2.\n";
	std::cout << "Lista inwestorow:\n";
	p->wypisz_liste(LISTA);
	std::cout << "Wartosci akcji:\n";
	p->wypisz_liste_akcji(TAB);
	std::cout << "\nZADANIE 3.\n";
	p->wczytaj_i_znajdz(LISTA, "Kowalski");
	p->wczytaj_i_znajdz(LISTA, "Stanczyk");
	std::cout << "\nZADANIE 4.\n";
	std::cout << "Nazwiska inwestorow:\n";
	p->przedzial(LISTA, 200);
	delete p;
	system("pause");
	return 0;
}