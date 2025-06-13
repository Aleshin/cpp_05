#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // === Canonical form ===
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // === Getters ===
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // === Signing logic ===
    void beSigned(const Bureaucrat& b);

    // === Exceptions ===
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// === Overload output stream ===
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
