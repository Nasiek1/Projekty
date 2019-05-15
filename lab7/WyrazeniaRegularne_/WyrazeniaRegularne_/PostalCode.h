#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <iostream>
class postalCode
{
	std::string fileName; //Nazwa pliku.
	std::vector <std::string> codesArr; //Vector na kody pocztowe
public:
	void readFile(); //Funkcja odczytuj¹ca kody.
	std::size_t codeAmount(); //Zwraca iloœæ kodów w tablicy.
	postalCode(std::string _fileName); //Konstruktor
	void printCodes(); //Wyswietla wczytane kody.
	~postalCode() = default;
};
