#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()

// === Constructor ===
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(NULL)); // Seed random once (safe для множества форм)
}

// === Copy constructor ===
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

// === Assignment operator ===
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

// === Destructor ===
RobotomyRequestForm::~RobotomyRequestForm() {}

// === Execute ===
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException(); // or NotSignedException
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises * rrrrrRRRRrrrr... zzzZZZzz...\n";

    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully 🤖✅\n";
    else
        std::cout << "Robotomy failed for " << _target << " ❌\n";
}
