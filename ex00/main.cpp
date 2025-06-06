#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bob("Bob", 75);
    std::cout << bob << std::endl;

    bob.incrementGrade();
    std::cout << "After increment: " << bob << std::endl;

    Bureaucrat copy = bob;
    std::cout << "Copy: " << copy << std::endl;

    return 0;
}
