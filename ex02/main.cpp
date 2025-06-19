#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 140);           // может только подписывать Shrubbery
        Bureaucrat alice("Alice", 40);        // выполняет Shrubbery и Robotomy
        Bureaucrat president("Zaphod", 1);    // выполняет всё

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n--- Signing phase ---\n";
        bob.signForm(shrub);           // ✅ OK
        alice.signForm(robot);         // ✅ OK
        president.signForm(pardon);    // ✅ OK

        std::cout << "\n--- Execution phase ---\n";
        alice.executeForm(shrub);      // ✅ Исполняется → создаёт garden_shrubbery
        alice.executeForm(robot);      // ✅ OK (или fail, 50%)
        bob.executeForm(pardon);       // ❌ слишком низкий grade
        president.executeForm(pardon); // ✅ OK

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
