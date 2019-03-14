#include<iostream>
#include"ReadFile.h"
int main()
{
	ReadFile name("plikWej.txt");
	name.readFile();
	return 0;
	//co jezeli w pliku dane beda charami wtedy jako int potraktowane
}