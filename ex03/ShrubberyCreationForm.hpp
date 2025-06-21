#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>  // for file creation
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    // Canonical form
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    // Execute action
    virtual void execute(Bureaucrat const& executor) const;
};

#endif
