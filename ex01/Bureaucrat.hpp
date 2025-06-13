#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    // Canonical form
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Accessors
    const std::string& getName() const;
    int getGrade() const;

    // Grade manipulation
    void incrementGrade(); // grade--
    void decrementGrade(); // grade++

    void signForm(Form& form);

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
