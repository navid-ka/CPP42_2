
#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
    std::string _file;

  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    void executeForm() const;
};
