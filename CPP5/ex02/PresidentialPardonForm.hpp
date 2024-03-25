#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {

  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &cpy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};
