#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
    _target = target;
    _file = target + "_shrubbery";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeReq()) {
    _target = cpy._target;
    _file = cpy._file;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        _target = rhs._target;
        _file = rhs._file;
        AForm::operator=(rhs);
    }
    return (*this);
}

void ShrubberyCreationForm::executeForm() const {
    std::ofstream out;
    out.open(this->_file.c_str());
    if (!out.is_open()) {
        std::cerr << "Could not write to " << this->_file << std::endl;
        out.close();
    }
    out << "    *\n";
    out << "   ***\n";
    out << "  *****\n";
    out << " ********\n";
    out << "***********\n";
    out << "   %%\n";
    out << "   %%\n";
    out.close();
}
