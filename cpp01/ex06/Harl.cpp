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
    Level level;

    if (levelt == "DEBUG") level = DEBUG;
    else if (levelt == "INFO") level = INFO;
    else if (levelt == "WARNING") level = WARNING;
    else if (levelt == "ERROR") level = ERROR;
    else level = static_cast<Level>(-1);

    switch (level)
    {
        case DEBUG:
            Harl::debug();
        case INFO:
            Harl::info();
        case WARNING:
            Harl::warning();
        case ERROR:
            Harl::error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
}