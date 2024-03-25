
#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};
