/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#pragma once

#include <iostream>
#include <string>

class Form {
private:
  const std::string _name;
  bool _isGradeSigned;
  const int _gradeSign;
  const int _gradeRequiredExec;

public:
  Form(std::string, int, int);
  ~Form();
  Form(const Form &);
  Form &operator=(const Form &);

  const std::string &getName() const;

  const bool isGradeSigned(int) const;
  const bool isGradeRequiredToExec(int) const;

  void beSigned(int);
  void beExecuted(int);

  class GradeTooHighException : public std::range_error{
  public:
    GradeTooHighException(const std::string &error);
  };
  class GradeTooLowException : public std::range_error{
  public:
    GradeTooLowException(const std::string &error);
  };
  
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

std::ostream &operator<<(std::ostream &out, const Form &rhs);
