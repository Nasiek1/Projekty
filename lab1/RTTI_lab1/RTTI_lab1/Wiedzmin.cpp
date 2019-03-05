#include "Wiedzmin.h"


Wiedzmin::Wiedzmin(const double weight, const char *name, const int iQ, const double damage)
	:Czlowiek(weight,name,iQ),
	dmg(damage)
{
	std::cout << "Konstruktor argumentowy Wiedzmin\n";
}
Wiedzmin::Wiedzmin()
{
	std::cout << "Konstruktor bezargumentowy Wiedzmin\n";
}


Wiedzmin::~Wiedzmin()
{
	std::cout << "Destruktor Wiedzmin\n";
}
void Wiedzmin::bij_potwora()
{
	dmg += 10;
	std::cout << "Wiedzmin bije potwora\n";
}
void Wiedzmin::jedz()
{
	double _waga = Czlowiek::getWaga();
	++_waga;
	std::cout << "Wiedzmin je\n";
}
void Wiedzmin::ucz_sie()
{
	int iQ = Czlowiek::getiQ();
	++iQ;
	std::cout << "Wiedzmin uczy sie\n";
}
double Wiedzmin::getDamage()
{
	return dmg;
}