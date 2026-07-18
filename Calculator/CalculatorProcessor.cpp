#include "CalculatorProcessor.h"


CalculatorProcessor* instance = nullptr;

CalculatorProcessor::CalculatorProcessor() {}


CalculatorProcessor* CalculatorProcessor::GetInstance()
{
    if (instance == nullptr)
        instance = new CalculatorProcessor();

    return instance;
}