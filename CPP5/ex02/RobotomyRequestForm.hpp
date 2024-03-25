
#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &cpy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};
