#pragma once

#include "AForm.hpp"
#include <iostream>

class AForm;

class Intern {
  private:
  public:
    Intern();
    ~Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    AForm *createShrubberyForm(const std::string &target) const;
    AForm *createRobotomyForm(const std::string &target) const;
    AForm *createPardonForm(const std::string &target) const;
    AForm *makeForm(const std::string &name, const std::string &target) const;
};
