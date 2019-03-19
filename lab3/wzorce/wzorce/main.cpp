#include<iostream>
#include"Tlista.h"
#include"Tprzechowywalnia.h"
template<typename T>
T dodawanie(T a, T b)
{
	return a + b;
}
int main()
{
	int ia = 45;
	int ib = 77;
	std::cout << "Wynik dodawania int: " << dodawanie(ia, ib) << std::endl;
	double da = 19.9;
	double db = 67.81;
	std::cout << "Wynik dodawania double: " << dodawanie(da, db) << std::endl;
	std::cout << dodawanie<int>(da, db) << std::endl;
	Tlista<int> Glowa;
	for (int elem : {1, 2, 3, 4, 5})
		Glowa.dodajElement(elem);
	Glowa.wyswietlListe();
	Glowa.usunListe();
	Glowa.wyswietlListe();
	Tprzechowywalnia<float>konto;
	std::cout << konto.co_mam() << std::endl;
	konto.wyczysc();
	konto.dodaj(5.09887);
	std::cout << konto.rabunek() << std::endl;
	Tprzechowywalnia<char> moje_znaki;
	moje_znaki.dodaj("TURURUR TUTU");
	std::cout << moje_znaki.co_mam() << std::endl;
	std::cout << moje_znaki.rabunek() << std::endl;
	moje_znaki.wyczysc();

	return 0;
}