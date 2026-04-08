#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void evaluate(const std::string &expression);

private:
    std::stack<double> _stack;

    bool isOperator(const std::string &token);
    void applyOperator(const std::string &op);
};

#endif