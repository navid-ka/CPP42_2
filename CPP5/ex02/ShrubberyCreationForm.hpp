
#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
    void executeForm() const;

  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};
