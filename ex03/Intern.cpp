#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// === Canonical form ===
Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// === Form creation functions ===
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// === Main factory method ===
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    typedef AForm* (*FormCreator)(const std::string& target);

    struct FormEntry {
        const char* name;
        FormCreator creator;
    };

    static const FormEntry forms[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPardon }
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(FormEntry); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    std::cerr << "Intern: form \"" << formName << "\" does not exist" << std::endl;
    return NULL;
}
