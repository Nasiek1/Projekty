#include "Czlowiek.h"

Czlowiek::Czlowiek()
{
	std::cout << "Konstruktor bezargumentowy Czlowiek\n";
}

Czlowiek::Czlowiek(const double weight, const char *name, const int iQ)
	:Ssak(weight),
	iq(iQ)
{
	imie = new char[strlen(name) + 1];
	strcpy_s(imie, strlen(name) + 1, name);
	std::cout << "Konstruktor argumentowy Czlowiek\n";
}
Czlowiek::~Czlowiek()
{
	delete[]imie;
	std::cout << "Destruktor Czlowiek\n";
}
void Czlowiek::jedz()
{
	//dodawanie do ssaka wagi
	std::cout << "Czlowiek je\n";
}
void Czlowiek::ucz_sie()
{
	iq += 2;
	std::cout << "Czlowiek uczy sie\n";
}
