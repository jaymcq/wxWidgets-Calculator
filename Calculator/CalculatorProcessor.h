#pragma once
#include <string>

class CalculatorProcessor
{
private:
	CalculatorProcessor();
	CalculatorProcessor* instance;

public:
	CalculatorProcessor* GetInstance();
	double Calculate(std::string& problem);
};

