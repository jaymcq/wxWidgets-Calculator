#include "CalculatorProcessor.h"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <vector>

namespace
{
    enum class TokenType { Number, Operator, Function, LeftParenthesis };

    struct Token
    {
        TokenType type;
        double number{};
        char symbol{};
        std::string name;
    };

    bool IsOperator(char character)
    {
        return character == '+' || character == '-' || character == '*' ||
            character == '/' || character == '%';
    }

    int Precedence(const Token& token)
    {
        if (token.type == TokenType::Function) return 3;
        if (token.symbol == '*' || token.symbol == '/' || token.symbol == '%') return 2;
        return 1;
    }

    std::string ToLower(std::string value)
    {
        for (char& character : value)
            character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
        return value;
    }

    void Apply(std::vector<double>& values, const Token& token)
    {
        if (token.type == TokenType::Function)
        {
            if (values.empty()) throw std::invalid_argument("Function is missing an argument.");
            double& value = values.back();
            if (token.name == "sin") value = std::sin(value);
            else if (token.name == "cos") value = std::cos(value);
            else if (token.name == "tan") value = std::tan(value);
            else throw std::invalid_argument("Unknown function.");
            return;
        }

        if (values.size() < 2) throw std::invalid_argument("Operator is missing an operand.");
        const double right = values.back(); values.pop_back();
        const double left = values.back(); values.pop_back();

        switch (token.symbol)
        {
        case '+': values.push_back(left + right); break;
        case '-': values.push_back(left - right); break;
        case '*': values.push_back(left * right); break;
        case '/':
            if (right == 0.0) throw std::invalid_argument("Cannot divide by zero.");
            values.push_back(left / right);
            break;
        case '%':
            if (right == 0.0) throw std::invalid_argument("Cannot take modulo by zero.");
            values.push_back(std::fmod(left, right));
            break;
        default: throw std::invalid_argument("Unknown operator.");
        }
    }
}

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
    static CalculatorProcessor instance;
    return &instance;
}

double CalculatorProcessor::Calculate(const std::string& expression) const
{
    std::vector<Token> output;
    std::vector<Token> operators;
    bool expectingOperand = true;

    for (std::size_t index = 0; index < expression.size();)
    {
        const unsigned char current = static_cast<unsigned char>(expression[index]);
        if (std::isspace(current)) { ++index; continue; }

        const bool signedNumber = expectingOperand && (expression[index] == '+' || expression[index] == '-') &&
            index + 1 < expression.size() && (std::isdigit(static_cast<unsigned char>(expression[index + 1])) || expression[index + 1] == '.');
        if (std::isdigit(current) || expression[index] == '.' || signedNumber)
        {
            if (!expectingOperand) throw std::invalid_argument("Missing operator before number.");
            const char* start = expression.c_str() + index;
            char* end = nullptr;
            const double value = std::strtod(start, &end);
            if (end == start || !std::isfinite(value)) throw std::invalid_argument("Invalid number.");
            index += static_cast<std::size_t>(end - start);
            output.push_back({ TokenType::Number, value });
            expectingOperand = false;
            continue;
        }

        if (std::isalpha(current))
        {
            const std::size_t start = index;
            while (index < expression.size() && std::isalpha(static_cast<unsigned char>(expression[index]))) ++index;
            const std::string name = ToLower(expression.substr(start, index - start));
            if (name != "sin" && name != "cos" && name != "tan")
                throw std::invalid_argument("Unknown function: " + name);
            if (!expectingOperand) throw std::invalid_argument("Missing operator before function.");
            operators.push_back({ TokenType::Function, 0.0, 0, name });
            continue;
        }

        if (expression[index] == '(')
        {
            if (!expectingOperand) throw std::invalid_argument("Missing operator before '('.");
            operators.push_back({ TokenType::LeftParenthesis });
            ++index;
            continue;
        }

        if (expression[index] == ')')
        {
            if (expectingOperand) throw std::invalid_argument("Parentheses are missing an operand.");

            bool foundOpeningParenthesis = false;
            while (!operators.empty())
            {
                if (operators.back().type == TokenType::LeftParenthesis)
                {
                    operators.pop_back();
                    foundOpeningParenthesis = true;
                    break;
                }
                output.push_back(operators.back());
                operators.pop_back();
            }
            if (!foundOpeningParenthesis) throw std::invalid_argument("Unmatched ')'.");

            // A function directly before parentheses applies to the grouped value.
            if (!operators.empty() && operators.back().type == TokenType::Function)
            {
                output.push_back(operators.back());
                operators.pop_back();
            }
            ++index;
            expectingOperand = false;
            continue;
        }

        if (IsOperator(expression[index]))
        {
            if (expectingOperand) throw std::invalid_argument("Expected a number or function.");
            Token token{ TokenType::Operator, 0.0, expression[index++] };
            while (!operators.empty() && operators.back().type != TokenType::LeftParenthesis &&
                Precedence(operators.back()) >= Precedence(token))
            {
                output.push_back(operators.back());
                operators.pop_back();
            }
            operators.push_back(token);
            expectingOperand = true;
            continue;
        }

        throw std::invalid_argument("Unsupported character in expression.");
    }

    if (output.empty()) throw std::invalid_argument("Enter an expression first.");
    if (expectingOperand) throw std::invalid_argument("Expression cannot end with an operator.");
    while (!operators.empty())
    {
        if (operators.back().type == TokenType::LeftParenthesis)
            throw std::invalid_argument("Unmatched '('.");
        output.push_back(operators.back());
        operators.pop_back();
    }

    std::vector<double> values;
    for (const Token& token : output)
    {
        if (token.type == TokenType::Number) values.push_back(token.number);
        else Apply(values, token);
    }
    if (values.size() != 1 || !std::isfinite(values.back()))
        throw std::invalid_argument("Calculation did not produce a finite result.");
    return values.back();
}
