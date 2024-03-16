/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(const std::string name, int grades)
    : _name(name), _grades(grades) {
  try {
    std::string err = "Name is empty\n";
    if (this->_name.empty())
      throw(4);
  } catch (int err) {
    ONLYPRINTFANS("Exception thown in " << err);
  }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
  _name = copy.getName();
  _grades = copy.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  this->_name = rhs.getName();
  this->_grades = rhs.getGrade();
  return *this;
}

const std::string &Bureaucrat::getName() const { return (_name); }

const int &Bureaucrat::getGrade() const { return (_grades); }
