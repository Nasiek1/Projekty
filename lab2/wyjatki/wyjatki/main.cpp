#include<iostream>
#include<string>
#include<exception>
class divide_by_zero :public std::exception
{
	const char* what() const throw()
	{
		return "Blad dzielenia przez zero\n";
	}

};
//int zabij_kalkulator(int a, int b)
//{
//	if (b == 0)
//	{
//		std::string wyjatek = "DZIELENIE PRZEZ ZERO";
//		throw wyjatek;
//	}
//	else if (b == 1)
//	{
//		int wyjatek = 1;
//		throw wyjatek;
//	}
//	else
//	return a / b;
//}
int zabij_kalkulator(int a, int b)
{
	if (b == 0)
	{
		divide_by_zero wyjatek;
		throw wyjatek;
	}
	else if (b==1)
	{
		std::bad_exception wyjatek;
		throw wyjatek;
	}
	else
		return a / b;
}
void zabij_ram(void)
{
	char* tab;
	for (int i = 0; i < 10; i++)
	{
		tab = new char[1024 * 1024 * 1024];
		int wyjatek=1;
		throw wyjatek;
	}
}
int main()
{
	std::cout << zabij_kalkulator(8, 2) << std::endl;
	std::cout << zabij_kalkulator(4, 8) << std::endl;
	try
	{
		//zabij_kalkulator(3, 0);
		zabij_kalkulator(3, 1);
	}
	catch (std::string wyjatek)
	{
		std::cout << "Wyrzucono wyjatek:" << wyjatek << std::endl;
	}
	catch (int wyjatek)
	{
		std::cout << "Wyrzucono wyjatek: dzielenie przez " << wyjatek << std::endl;
	}
	try
	{
		try
		{
			//zabij_kalkulator(4, 0);
			zabij_kalkulator(4, 1);
		}
		catch (std::string wyjatek)
		{
			std::cout << "Wyrzucono wyjatek: " << wyjatek << std::endl;
			std::cout << "Wewnetrzny catch()\n";
		}
		catch (...)
		{
			throw;
		}
	}
	catch(int wyjatek)
	{
		std::cout << "Wyrzucono wyjatek: dzielenie przez " << wyjatek << std::endl;
		std::cout << "Zewnetrzny catch()\n";
	}
	try
	{
		zabij_ram();
	}
	catch (int wyjatek)
	{
		std::bad_alloc wyjateczek;
		std::cout << "Zlapano wyjatek: " << wyjatek << std::endl;
		std::cout << wyjateczek.what();
	}
	try
	{
		//zabij_kalkulator(8, 4);
		//zabij_kalkulator(8, 0);
		zabij_kalkulator(8, 1);
	}
	catch(const std::exception& wyjatek)
	{
		std::cout << wyjatek.what() << std::endl;
	}
	return 0;
}