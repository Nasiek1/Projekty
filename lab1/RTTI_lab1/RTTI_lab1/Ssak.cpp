#include "Ssak.h"

Ssak::Ssak(double weight)
	:waga(weight)
{
	std::cout << "Konstruktor argumentowy Ssak\n";
}

Ssak::Ssak()
{
	std::cout << "Konstruktor bezargumentowy Ssak\n";
}


Ssak::~Ssak()
{
	std::cout << "Destruktor Ssak\n";
}
void Ssak::jedz()
{
	++waga;
	std::cout<<"Ssak je\n"<<"Waga Ssak: " << waga << "\n";
}
double Ssak::getWaga()
{
	return waga;
}