#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>
#include<chrono>
enum sadzonka {
	ogorek,
	pomidor,
	ziemniak,
	burak,
	marchewka
};
enum karty
{
	dwa,
	trzy,
	cztery,
	piec,
	szesc,
	siedem,
	osiem,
	dziewiec,
	dziesiec,
	walet,
	dama,
	krol,
	as,
	joker
};
std::ostream& operator<<(std::ostream & o, std::vector<sadzonka>&s)
{
	std::vector<sadzonka>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
	{
		switch (*iter)
		{
		case ogorek: 
			o << "O" << " | ";
			break;
		case pomidor:
			o << "P" << " | ";
			break;
		case ziemniak:
			o << "Z" << " | ";
			break;
		case burak:
			o << "B" << " | ";
			break;
		case marchewka:
			o << "M" << " | ";
			break;
		default:
			std::invalid_argument("Nieznana sadzonka\n");
		}
	}
	return o;
}

std::ostream& operator <<(std::ostream& o, std::vector<karty>& s)
{
	std::vector <karty>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
	{
		switch (*iter)
		{
		case dwa: 
			o << "2"; break;
		case trzy: 
			o << "3"; break;
		case cztery: 
			o << "4"; break;
		case piec: 
			o << "5"; break;
		case szesc: 
			o << "6"; break;
		case siedem: 
			o << "7"; break;
		case osiem: 
			o << "8"; break;
		case dziewiec: 
			o << "9"; break;
		case dziesiec: 
			o << "10"; break;
		case walet: 
			o << "J"; break;
		case dama: 
			o << "D"; break;
		case krol: 
			o << "K"; break;
		case as: 
			o << "A"; break;
		case joker: 
			o << "*"; break;
		}
		
	}
	return o;
}
void marchewki_na_inne(std::vector<sadzonka>::iterator poczatek, std::vector<sadzonka>::iterator koniec, sadzonka s)
{
	std::replace(poczatek, koniec, marchewka, s);
}
void sadzac_ziemniaka_osiedlasz_buraka(std::vector<sadzonka>& s)
{
	for (std::vector<sadzonka>::iterator it = s.begin(); it != s.end(); it++)
	{
		std::vector<sadzonka>::iterator idx_ = std::find(it, s.end(), ziemniak);
		if (idx_ != s.end())
		{
			int idx = std::distance(s.begin(), idx_);
			s.erase(s.begin() + idx);
			s.insert(s.begin() + idx, burak);
		}
	}

}
void binarnie_cztery(std::vector<sadzonka>&s)
{
	std::vector<sadzonka>wzor({ pomidor,ogorek,ogorek });
	std::vector<sadzonka>::iterator idx = std::search(s.begin(), s.end(), wzor.begin(), wzor.end());
	if (idx != s.end())
	{
		int idx_ = std::distance(s.begin(), idx);
		std::swap_ranges(idx, s.begin() + (idx_ + 3), s.begin() + 17);
	}
}
void przygotuj_talie(std::vector<karty>& t)
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			t.push_back(static_cast<karty>(i+2));
		}
	}
	if (rand() % 2)
	{
		t[0] = joker;
	}
	std::random_shuffle(t.begin(), t.end());
	//W 50% przypadków jedna z dwójek powinna zostaæ zamieniona na jokera
}
bool isJoker(int i)
{
	if (i == joker)
		return true;
	else
		return false;

}
void rozdaj_graczom(const std::vector<karty>& t, std::vector<karty>&g1, std::vector<karty>&g2)
{

	g1.assign(t.begin(), t.begin() + 26);
	g2.assign(t.begin() + 26, t.end());

	std::vector<karty>::iterator it1 = std::find_if(g1.begin(), g1.end(), isJoker);
	if (it1 != g1.end())
	{
		*it1 = dwa;
	}
	std::vector<karty>::iterator it2 = std::find_if(g2.begin(), g2.end(), isJoker);
	if (it2 != g2.end())
	{
		*it2 = dwa;
	}

	std::sort(g1.begin(), g1.end());
	std::sort(g2.begin(), g2.end());
}
int main()
{
	srand(time(NULL));
	std::vector<sadzonka> pole1(20);
	fill(pole1.begin(), pole1.end(), marchewka);
	std::cout << pole1;
	std::cout << "\n";
	marchewki_na_inne(pole1.begin(), pole1.begin() + 4,ziemniak);
	marchewki_na_inne(pole1.begin(), pole1.begin() + 9, pomidor);
	marchewki_na_inne(pole1.begin(), pole1.begin() + 15, ogorek);
	std::cout << pole1;
	std::cout << "\n";

	std::random_shuffle(pole1.begin(), pole1.begin()+ 15);
	std::cout << pole1;
	std::cout << "\n";

	std::vector<sadzonka> pole2(20);
	std::copy(pole1.begin(), pole1.end(), pole2.begin());
	std::cout << pole2;
	std::cout << "\n";
	std::vector<sadzonka>pgr;
	pgr.insert(pgr.end(), pole1.begin(), pole1.end());
	pgr.insert(pgr.end(), pole2.begin(), pole2.end());
	std::cout << pole1;
	std::cout << "\n";
	std::cout << pole2;
	std::cout << "\n";
	std::cout << pgr;
	std::cout << "\n";

	std::vector<karty>talia;
	std::vector<karty> gracz1;
	std::vector<karty>gracz2;
	przygotuj_talie(talia);
	std::cout << talia;
	std::cout << "\n";
	rozdaj_graczom(talia, gracz1, gracz2);
	std::cout << gracz1;
	std::cout << "\n";
	std::cout << gracz2;
	std::cout << "\n";
		return 0;
}