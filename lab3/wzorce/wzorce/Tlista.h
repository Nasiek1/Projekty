#pragma once
template<typename T>
class Tlista
{
	struct element
	{
		T wartosc;
		element *pNext;
	};
	element *pHead;
public:
	Tlista()
		:pHead(nullptr)
	{

	}
	void dodajElement(const T& dane)
	{
		element *pNowy = new element;
		pNowy->wartosc = dane;
		pNowy->pNext = pHead;
		pHead = pNowy;

	}
	void wyswietlListe()
	{
		element *p = pHead;
		while (p)
		{
			std::cout << p->wartosc << " -> ";
			p = p->pNext;
		}
	}
	void usunListe()
	{
		element *p = pHead;
		while (p)
		{
			p = p->pNext;
			delete pHead;
			pHead = p;
		}
	}
};