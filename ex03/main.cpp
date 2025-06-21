#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    AForm* form = NULL;

    std::cout << "\n--- Testing: ShrubberyCreationForm ---\n";
    form = intern.makeForm("shrubbery creation", "Park");
    if (form) {
        Bureaucrat gardener("Bob", 100); // grade OK for signing/executing
        gardener.signForm(*form);
        gardener.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Testing: RobotomyRequestForm ---\n";
    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat tech("Alice", 40); // OK for both sign and exec
        tech.signForm(*form);
        tech.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Testing: PresidentialPardonForm ---\n";
    form = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        Bureaucrat president("Zaphod", 1); // max access
        president.signForm(*form);
        president.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Testing: Invalid form ---\n";
    form = intern.makeForm("coffee request", "Marvin");
    if (!form)
        std::cout << "Form creation failed as expected.\n";

    return 0;
}
