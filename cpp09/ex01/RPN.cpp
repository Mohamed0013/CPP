#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::applyOperator(const std::string &op)
{
    if (_stack.size() < 2) //stack khas ykounou fih 2 numbers
        throw std::runtime_error("Error");

    double b = _stack.top(); _stack.pop();
    double a = _stack.top(); _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        _stack.push(a / b);
    }
}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
            applyOperator(token);
        else
        {
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error");
            _stack.push(token[0] - '0');
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stack.top() << std::endl;
}