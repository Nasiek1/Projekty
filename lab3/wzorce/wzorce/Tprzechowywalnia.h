#pragma once
#include<string>
template<typename T>
class Tprzechowywalnia
{
	T cos;
public:
	Tprzechowywalnia()
	{
		wyczysc();
	}
	void wyczysc()
	{
		cos = {};
	}
	void dodaj(T nowy)
	{
		cos += nowy;
	}
	T co_mam()
	{
		return cos;
	}
	T rabunek()
	{
		T rabuneczek = cos;
		wyczysc();
		return rabuneczek;
	}

};
template<>
class Tprzechowywalnia<char>
{
	std::string cos;
public:
	Tprzechowywalnia()
	{
		wyczysc();
	}
	void wyczysc()
	{
		cos.clear();
	}
	void dodaj(const std::string &nowy)
	{
		cos += nowy;
	}
	std::string co_mam()
	{
		return cos;
	}
	std::string rabunek()
	{
		std::string rabuneczek = cos;
		wyczysc();
		return rabuneczek;
	}
};