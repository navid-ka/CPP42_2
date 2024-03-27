#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 145, 137) {
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeReq()) {
    _target = cpy._target;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    if (this != &rhs) {
        _target = rhs._target;
        AForm::operator=(rhs);
    }
    return (*this);
}
