#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::harlFilter(std::string levelt)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])() = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };

    int i = 0;
    for (; i < 4; i++)
    {
        if (levels[i] == levelt)
            break;
    }

    switch (i)
    {
        case 0:
            (this->*functions[0])();
            // intentional cascade
            (this->*functions[1])();
            (this->*functions[2])();
            (this->*functions[3])();
            break;
        case 1:
            (this->*functions[1])();
            (this->*functions[2])();
            (this->*functions[3])();
            break;
        case 2:
            (this->*functions[2])();
            (this->*functions[3])();
            break;
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
