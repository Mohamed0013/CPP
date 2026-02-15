#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequest", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Brrrrzzzz... drilling noises...\n";

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed\n";
}
