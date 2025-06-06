#include "Bureaucrat.hpp"

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade) {
    std::cout << "Parameterized constructor called for " << _name << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called for " << _name << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy assignment operator called for " << _name << std::endl;
    if (this != &other) {
        // _name is const, so we can't assign to it
        this->_grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for " << _name << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Grade manipulation
void Bureaucrat::incrementGrade() {
    --_grade; // no bounds check for now
}

void Bureaucrat::decrementGrade() {
    ++_grade; // no bounds check for now
}

// Output stream overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
