#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : _target(target), AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) {
    _target = cpy._target;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        _target = rhs._target;
    }
    return (*this);
}

void ShrubberyCreationForm::executeForm() {}
