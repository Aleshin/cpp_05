#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 0); // Invalid: too high
    } catch (std::exception& e) {
        std::cerr << "Exception during Alice creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 151); // Invalid: too low
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

    return 0;
}
