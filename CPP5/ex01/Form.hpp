/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <ostream>

class Bureaucrat;
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
  int getGradeSign() const;
  int getGradeReq() const;
  bool getIsGradeSigned() const;

  void beSigned(const Bureaucrat &);
  void isGradeValid(int);

  class GradeTooHighException : public std::range_error {
  public:
    GradeTooHighException(const std::string &error);
  };
  class GradeTooLowException : public std::range_error {
  public:
    GradeTooLowException(const std::string &error);
  };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif // FORM_HPP