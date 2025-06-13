#include "Form.hpp"
#include "Bureaucrat.hpp"

// === Constructor ===

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// === Copy constructor ===

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// === Assignment operator ===

Form& Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

// === Destructor ===

Form::~Form() {}

// === Getters ===

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// === beSigned method ===

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// === Exception implementations ===

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high for Form";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low for Form";
}

// === operator<< overload ===

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName()
       << ", form requires grade " << form.getGradeToSign()
       << " to sign, " << form.getGradeToExecute()
       << " to execute, signed: "
       << (form.getIsSigned() ? "true" : "false");
    return os;
}
