/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#define ONLYPRINTFANS(x)                                                       \
  std::cerr << x << " LINE: " << __LINE__ << " FILE: " << __FILE__ << std::endl;
#define ONLYPRINTNOFANS(x, y, z) std::cout << x << y << z << std::endl;

class Form;

class Bureaucrat {

private:
  std::string _name;
  int _grades;

public:
  Bureaucrat(const std::string &name, int grades);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &copy);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  const std::string &getName() const;
  const int &getGrade() const;

  void incrementGrade(int);
  void incrementGrade();

  void decrementGrade(int);
  void decrementGrade();
  void isGradeValid(int grade);

  void signForm(Form &);
  class GradeTooHighException : public std::range_error {
  public:
    GradeTooHighException(const std::string &msg);
  };
  class GradeTooLowException : public std::range_error {
  public:
    GradeTooLowException(const std::string &msg);
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);


#endif // BUREAUCRAT_HPP