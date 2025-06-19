#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// === Constructor ===
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// === Copy constructor ===
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

// === Assignment operator ===
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

// === Destructor ===
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// === Execute ===
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException(); // or custom NotSignedException
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) {
        std::cerr << "Failed to create file: " << _target << "_shrubbery" << std::endl;
        return;
    }

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "       | |" << std::endl;
    ofs << "      /   \\" << std::endl;

    ofs.close();
}
