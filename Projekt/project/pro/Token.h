#pragma once
#include<iostream>
#include<variant>
enum Type { PLUS, NUMBER,EOS};
struct token
{
	Type type;

	std::variant<int, double> value;
	token();
	bool operator==(const token& tok);
	bool operator!=(const token& tok);
	token(Type type);
};
