

#pragma once

#include <iostream>
#include <string>

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeSigned;
  const int _gradeReq;

public:
  Form(const std::string, const int);
  ~Form();
  Form(const Form &);
  Form &operator=(const Form &);
};
