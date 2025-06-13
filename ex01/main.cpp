#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // === Bureaucrat creation tests (Exercise 00) ===

    try {
        Bureaucrat b1("Alice", 0); // Invalid: grade too high
    } catch (std::exception& e) {
        std::cerr << "Exception during Alice creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 151); // Invalid: grade too low
    } catch (std::exception& e) {
        std::cerr << "Exception during Bob creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 1);
        std::cout << b3 << std::endl;
        b3.incrementGrade(); // Should throw: already at highest grade
    } catch (std::exception& e) {
        std::cerr << "Exception during Charlie promotion: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Diana", 150);
        std::cout << b4 << std::endl;
        b4.decrementGrade(); // Should throw: already at lowest grade
    } catch (std::exception& e) {
        std::cerr << "Exception during Diana demotion: " << e.what() << std::endl;
    }

    std::cout << "==== Now testing Forms (Exercise 01) ====" << std::endl;

    // === Form creation and signing tests ===

    try {
        Form formA("TaxForm", 50, 25);
        std::cout << formA << std::endl;

        Bureaucrat bob("Bob", 45);
        Bureaucrat alice("Alice", 60);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        // Alice tries to sign (not enough grade)
        alice.signForm(formA);
        std::cout << formA << std::endl;

        // Bob tries to sign (has sufficient grade)
        bob.signForm(formA);
        std::cout << formA << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception during form tests: " << e.what() << std::endl;
    }

    std::cout << "==== Testing invalid Forms ====" << std::endl;

    // === Form creation with invalid grades ===

    try {
        Form invalidFormHigh("InvalidHigh", 0, 20);
    } catch (const std::exception& e) {
        std::cerr << "Exception during InvalidHigh form creation: " << e.what() << std::endl;
    }

    try {
        Form invalidFormLow("InvalidLow", 10, 200);
    } catch (const std::exception& e) {
        std::cerr << "Exception during InvalidLow form creation: " << e.what() << std::endl;
    }

    return 0;
}
