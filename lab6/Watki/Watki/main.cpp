#include<iostream>
#include<thread>
#include<string>
#include<fstream>
#include<vector>
#include<mutex>
using namespace std;
using namespace std::chrono;
std::mutex muteks;
class Napis
{
	std::string napis;
public:
	Napis();
	Napis(const std::string& nowyNapis);
	void porownaj(const std::string & _napis);
	void zamien_stringi(std::string &_napis);
	void sprawdz_przypisanie();
	~Napis();

};
void Napis::sprawdz_przypisanie()
{
	std::cout << "Przypisanie\n";
}

void Napis::zamien_stringi(std::string &_napis)
{
	std::swap(napis, _napis);
}
Napis::Napis()
{

}
Napis::Napis(const std::string & nowyNapis)
	:napis(nowyNapis)
{

}
void Napis::porownaj(const std::string & _napis)
{
	if (napis.size() == _napis.size())
		std::cout << "Napisy sa rownej dlugosci\n";
	else
		std::cout << "Napisy maja rozna dlugosc\n";
}
Napis::~Napis()
{

}
void odwroc_string(std::string & _napis)
{
	for (int i = 0; i < _napis.size() / 2; i++)
	{
		std::swap(_napis[i], _napis[_napis.size() - 1 - i]);
	}
}
bool ZliczanieLiterNieoptymalnie(string NazwaPliku)
{
	const int rozmiar = 26;			//ilosc liter
	int tab[rozmiar] = { 0 };		//tablica przechowujaca ilosci wystapien poszczegolnych liter
	int suma = 0;					//suma liter w pliku
	string wiersz;					//zmienna przechowujaca wczytany wiersz z pliku
	for (int i = 0; i < rozmiar; i++)
	{
		ifstream plik(NazwaPliku);
		if (plik.good())
		{
			while (!plik.eof())
			{
				getline(plik, wiersz);		//pobieranie wiersza z pliku
				for (int j = 0; j < wiersz.size(); j++)
				{
					if (wiersz[j] >= 'A' && wiersz[j] <= 'Z')
						wiersz[j] += 32;		//zamiana na male litery
					if (wiersz[j] == (char)(i + 'a'))
					{
						tab[i]++;			//inkrementacja odpowiedniego elementu tablicy
					}
				}
			}
		}
		else
		{
			cout << "Blad odczytu pliku.";
			return false;
		}
	}
	muteks.lock(); //sekwencyjnie wypisuja ale obliczaja w tym samym czasie
	cout << NazwaPliku << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		cout << (char)(i + 97) << ". " << tab[i] << endl;			//wyswietlanie tablicy
		suma += tab[i];
	}
	cout << "Ilosc wszystkich liter: " << suma << endl;
	muteks.unlock();
	return true;
}
int main()
{
	//Zad.1
	std::string _napis = "Watki";
	Napis napisik("Kwiat");
	std::thread t1(&Napis::porownaj, napisik, _napis);
	t1.join();
	std::thread t2(&Napis::zamien_stringi, std::ref(napisik), std::ref(_napis));
	t2.join();
	//Zad.2
	std::thread t3(odwroc_string, std::ref(_napis));
	t3.join();
	//Zad.3
	std::thread t4;
	std::cout << "Czy watek sie wykonuje? " << t4.joinable() << "\n";
	t4 = std::thread(&Napis::sprawdz_przypisanie, napisik);
	t4.join();



	high_resolution_clock::time_point time1 = high_resolution_clock::now();

	ZliczanieLiterNieoptymalnie("Krzyzacy.txt");
	ZliczanieLiterNieoptymalnie("Ogniem i mieczem.txt");
	ZliczanieLiterNieoptymalnie("Pan Tadeusz.txt");
	ZliczanieLiterNieoptymalnie("Potop.txt");
	ZliczanieLiterNieoptymalnie("Quo vadis.txt");

	high_resolution_clock::time_point time2 = high_resolution_clock::now();

	duration<double> time_span = time2 - time1;

	std::cout << "To zajelo: " << time_span.count() << " sekund" << "\n";

	time1 = high_resolution_clock::now();

	std::vector<std::thread> wateczki;
	wateczki.push_back(std::thread(ZliczanieLiterNieoptymalnie, "Krzyzacy.txt"));
	wateczki.push_back(std::thread(ZliczanieLiterNieoptymalnie, "Ogniem i mieczem.txt"));
	wateczki.push_back(std::thread(ZliczanieLiterNieoptymalnie, "Pan Tadeusz.txt"));
	wateczki.push_back(std::thread(ZliczanieLiterNieoptymalnie, "Potop.txt"));
	wateczki.push_back(std::thread(ZliczanieLiterNieoptymalnie, "Quo vadis.txt"));

	for (auto &element : wateczki)
		element.join();
	time2 = high_resolution_clock::now();
	time_span = time2 - time1;
	std::cout << "To zajelo: " << time_span.count() << " sekund" << "\n";
	return 0;
}