#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy) { *this = cpy; }

Intern &Intern::operator=(const Intern &cpy) {
    (void)cpy;
    return (*this);
}

Intern::~Intern(void) {}

AForm *Intern::createShrubberyForm(const std::string &target) const {
    return (new ShrubberyCreationForm(target));
}
AForm *Intern::createRobotomyForm(const std::string &target) const {
    return (new RobotomyRequestForm(target));
}
AForm *Intern::createPardonForm(const std::string &target) const {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name,
                        const std::string &target) const {

    return NULL;
}
