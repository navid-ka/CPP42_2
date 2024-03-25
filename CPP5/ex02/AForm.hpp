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
#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat;
class AForm {
  private:
    const std::string _name;
    bool _isGradeSigned;
    const int _gradeSign;
    const int _gradeRequiredExec;

  public:
    AForm(std::string, int, int);
    ~AForm();
    AForm(const AForm &);
    AForm &operator=(const AForm &);

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

std::ostream &operator<<(std::ostream &out, const AForm &rhs);
