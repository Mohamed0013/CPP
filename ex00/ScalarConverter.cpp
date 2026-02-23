#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string& s) {
    double value;

    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'') {
        value = static_cast<double>(s[1]);
    }
    else if (s == "nan" || s == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (s == "+inf" || s == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (s == "-inf" || s == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else {
        char* end;
        value = std::strtod(s.c_str(), &end);
        if (*end != '\0' && *end != 'f') {
            std::cout << "Error: invalid input\n";
            return ;
        }
    }

    // print char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else {
        char c = static_cast<char>(static_cast<int>(value));
        if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }

    // print int
    if (std::isnan(value) || std::isinf(value) ||
        value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    // print float
    std::cout << std::fixed << std::setprecision(1);
    float f = static_cast<float>(value);
    if (std::isnan(f))
        std::cout << "float: nanf\n";
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << "\n";
    else
        std::cout << "float: " << f << "f\n";

    // print double
    if (std::isnan(value))
        std::cout << "double: nan\n";
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << "\n";
    else
        std::cout << "double: " << value << "\n";
}
