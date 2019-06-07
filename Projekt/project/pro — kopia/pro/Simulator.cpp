#include "Simulator.h"

Simulator::Simulator()
{
	input = InputStream("data.txt");
}

Simulator::Simulator(const std::string & nameFile)
{
	input = InputStream(nameFile);

}
std::pair<double, double> Simulator::countResultAndTimeOfCalc(const std::string & expression) //function to count result (value) of all arithmetic operations in expressions and determine time of calculation 
{
		AnalyzerLL analyzer(expression);
		std::pair<double, double> resultAndTimeOfCalc;
		std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
		analyzer.interpret();
		double calculationsResult=analyzer.calculate();
		
		std::chrono::high_resolution_clock::time_point stopTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = stopTime - startTime;
		resultAndTimeOfCalc = { calculationsResult,time_span.count() };
		return resultAndTimeOfCalc;
}
std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, Comparator> Simulator::sortData(std::map<PrefixAndInfixForm, resultAndTimeOfCalc> ranking) //function to sort data in ascending order
{
	Comparator compFunctor =
		[](std::pair<PrefixAndInfixForm, resultAndTimeOfCalc> elem1, std::pair<PrefixAndInfixForm, resultAndTimeOfCalc> elem2)
	{
		return elem1.second.second < elem2.second.second;
	};
	
	std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, Comparator> setOfRanking(
		ranking.begin(), ranking.end(), compFunctor);
	return setOfRanking;
}
std::string Simulator::determineInfixForm(const std::string & expression) // function to determine infix form od expression -> building abstract syntax tree and check correctness of expression with considered grammar
{
	AnalyzerLL analyzer(expression);
	analyzer.interpret();
	return analyzer.determineInfixForm();
}
void Simulator::runSimulation() //function to run/generate all operations on each expression from file, operated with them and write received results to file
{
	std::vector<std::string> expressions = input.readData();
	std::map<PrefixAndInfixForm,resultAndTimeOfCalc> ranking;

	for (std::string element : expressions)
	{
		ranking.insert({ { element,determineInfixForm(element)},{countResultAndTimeOfCalc(element)} });

	}
	std::set <std::pair<PrefixAndInfixForm,resultAndTimeOfCalc>, Comparator > orderedRanking = sortData(ranking);
	writeToFile(orderedRanking);
}
void Simulator::writeToFile( std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>, Comparator>orderedRanking) //function to write whole calculated data to file
{
std::ofstream ofs("Results.txt");
	if (ofs)
	{
		std::set<std::pair<PrefixAndInfixForm, resultAndTimeOfCalc>> ::iterator it; 
		
		for (it = orderedRanking.begin(); it != orderedRanking.end(); it++)
		{
			std::pair<PrefixAndInfixForm, resultAndTimeOfCalc> m = *it; 
			if(it==orderedRanking.begin())
				ofs << "* Expression, that has the fastest calculations: *\n";

			ofs << "Prefix form of expression: ";
			ofs << m.first.first << "\n";
			ofs << "Infix form of expression: ";
			ofs << m.first.second << "\n";
			ofs << "Calculations' result: ";
			ofs << m.second.first << "\n";
			ofs << "Time of calculating: ";
			ofs << m.second.second << "\n";
			ofs << std::endl;
		}
		ofs.close();
	}
}

Simulator::~Simulator()
{
}


