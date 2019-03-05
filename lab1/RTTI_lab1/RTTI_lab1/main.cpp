#include<iostream>
#include"Ssak.h"
#include"Czlowiek.h"
#include"Wiedzmin.h"
#include<ctime>
#include<cstdlib>
#include<typeinfo>
// dynamic_cast <Typ*>(pt) przeksztalca wskaznik pt na wskaznik 
//typu Typ jesli wskazywany obiekt *pt jest klasy Typ lub klasy pochodnej od Typ
//jesli wyrazenie nie jest poprawne zwraca nullptr
//tamagotchi
Ssak* stworz_obiekt()
{
	int ktory = rand() % 3;
	if (ktory == 2) //stworz Ssaka
		return new Ssak(rand() % 200);
	else if (ktory == 1) //stworz Czlowieka
		return new Czlowiek(rand() % 200, "Randomowe imie", rand() % 200);
	else
		return new Wiedzmin(rand() % 200, "Randomowe imie", rand() % 200, rand() % 100);
}
int main()
{
	srand(time(NULL));
	Ssak* tablica[10];
	for (int i = 0; i < 10; i++)
		tablica[i] = stworz_obiekt();
	for (int i = 0; i < 10; i++)
		std::cout << "Obiekt nr: " << i << " jest klasy: " << typeid(*tablica[i]).name() << "\n";
	for (int i = 0; i < 10; i++)
	{
		tablica[i]->jedz();
		if (typeid(*tablica[i]).name() == typeid(Czlowiek).name())
		{
			dynamic_cast<Czlowiek*>(tablica[i])->ucz_sie();
			if (typeid(*tablica[i]).name() == typeid(Wiedzmin).name())
				dynamic_cast<Wiedzmin*>(tablica[i])->bij_potwora();
		}
	}
	Ssak* tab[30];
	for (int i = 0; i < 30; i++)
		tab[i] = stworz_obiekt();
	int suma = 0;
	int ileWiedzminow = 0;
	for (int i = 0; i < 30; i++)
	{
		if (typeid(*tab[i]).name() == typeid(Wiedzmin).name())
		{
			suma += dynamic_cast<Wiedzmin*>(tab[i])->getDamage();
			ileWiedzminow++;
		}
	}
	if (suma / ileWiedzminow > 0)
		std::cout << "Srednia wartosc obrazen wynosi: " << suma / ileWiedzminow << "\n";
	for (int i = 0; i < 30; i++)
		delete tab[i];
	for (int i = 0; i < 10; i++)
		delete tablica[i];
	return 0;
}