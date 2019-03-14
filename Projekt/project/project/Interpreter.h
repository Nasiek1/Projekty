#pragma once //czy uzywac namespace Interpreter a do Expression interfejs?
class Interpreter
{
public:
	Interpreter();
	virtual void interpret()
	{}
	virtual ~Interpreter();
};

