#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    srand(time(NULL));

    int r = rand() % 3;

    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C\n";
    }
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
    } catch (std::exception&) {}
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
    } catch (std::exception&) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
    } catch (std::exception&) {}
}

Base::~Base() {}
