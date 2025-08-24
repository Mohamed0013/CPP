#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing DEBUG level:\n";
    harl.complain("DEBUG");

    std::cout << "\nTesting INFO level:\n";
    harl.complain("INFO");

    std::cout << "\nTesting WARNING level:\n";
    harl.complain("WARNING");

    std::cout << "\nTesting ERROR level:\n";
    harl.complain("ERROR");

    std::cout << "\nTesting unknown level:\n";
    harl.complain("SILLY");

    return 0;
}
