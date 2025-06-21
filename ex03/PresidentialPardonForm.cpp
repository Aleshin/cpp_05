#include "PresidentialPardonForm.hpp"
#include <iostream>

// === Constructor ===
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// === Copy constructor ===
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

// === Assignment operator ===
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

// === Destructor ===
PresidentialPardonForm::~PresidentialPardonForm() {}

// === Execute ===
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException(); // или NotSignedException
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox. 🕊️" << std::endl;
}
