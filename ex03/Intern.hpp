#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    // Canonical form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Core functionality
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
