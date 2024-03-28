#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
    std::string _target;

  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &cpy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    void executeForm() const;
};
