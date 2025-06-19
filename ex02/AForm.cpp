#include "AForm.hpp"
#include "Bureaucrat.hpp"

// === Constructor ===

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// === Copy constructor ===

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// === Assignment operator ===

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

// === Destructor ===

AForm::~AForm() {}

// === Getters ===

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// === beSigned method ===

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// === Exception implementations ===

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high for Form";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low for Form";
}

// === operator<< overload ===

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
    os << aform.getName()
       << ", form requires grade " << aform.getGradeToSign()
       << " to sign, " << aform.getGradeToExecute()
       << " to execute, signed: "
       << (aform.getIsSigned() ? "true" : "false");
    return os;
}
