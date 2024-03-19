

#pragma once

#include <iostream>
#include <string>

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeSign;
  const int _gradeRequiredExec;

public:
  Form(std::string, int, int);
  ~Form();
  Form(const Form &);
  Form &operator=(const Form &);
};
