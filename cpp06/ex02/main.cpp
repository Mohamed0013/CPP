#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base* obj = generate();

    std::cout << "identify by pointer : ";
    identify(obj);

    std::cout << "identify by reference: ";
    identify(*obj);

    delete obj;
    return 0;
}