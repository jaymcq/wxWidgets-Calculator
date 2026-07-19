#pragma once
#include <string>

class CalculatorProcessor
{
public:
    static CalculatorProcessor* GetInstance();


    double Calculate(const std::string& expression) const;

    CalculatorProcessor(const CalculatorProcessor&) = delete;
    CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

private:
    CalculatorProcessor() = default;
};

