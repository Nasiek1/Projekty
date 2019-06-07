#pragma once
#include<vector>
#include<string>
#include"AnalyzerLL.h"
#include"InputStream.h"
#include<map>
#include<fstream>
#include<thread>
#include<algorithm>
#include<functional>
#include<set>
typedef std::pair<std::string, std::string> PrefixAndInfixForm;
typedef std::pair<double, double> resultAndTimeOfCalc;
typedef std::function<bool(std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, std::pair < PrefixAndInfixForm, resultAndTimeOfCalc>)> Comparator;

class Simulator
{
	InputStream input;
public:
	Simulator();
	Simulator(const std::string& nameFile);
	void runSimulation();
	std::pair<double, double> countResultAndTimeOfCalc(const std::string & expression);
	std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, Comparator> sortData(std::map<PrefixAndInfixForm, resultAndTimeOfCalc> ranking);
	std::string determineInfixForm(const std::string& expression);
	void writeToFile(std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, Comparator> orderedRanking);
	~Simulator();
};

