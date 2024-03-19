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
#include <ostream>
#include <stdexcept>
#include <string>

Bureaucrat::Bureaucrat(const std::string &name, int grades)
    : _name(name), _grades(grades) {
  try {
    if (this->_name.empty())
      throw std::invalid_argument("name cannot be empty");
  } catch (std::invalid_argument &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  }
  try {
    isGradeValid(_grades);
  } catch (GradeTooHighException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  } catch (GradeTooLowException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
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

void Bureaucrat::incrementGrade(int grade) {
  try {
    this->_grades += grade;
    isGradeValid(grade);
  } catch (GradeTooHighException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  } catch (GradeTooLowException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  }
}

void Bureaucrat::decrementGrade(int grade) {
  try {
    this->_grades -= grade;
    isGradeValid(this->_grades);
  } catch (GradeTooHighException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  } catch (GradeTooLowException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  }
}

void Bureaucrat::incrementGrade() {
  try {

    this->_grades++;
    isGradeValid(this->_grades);
  } catch (GradeTooHighException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  } catch (GradeTooLowException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  }
}

void Bureaucrat::decrementGrade() {
  try {
    this->_grades--;
    isGradeValid(this->_grades);
  } catch (GradeTooHighException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  } catch (GradeTooLowException &err) {
    ONLYPRINTFANS("Exception thown in " << err.what());
  }
}

void Bureaucrat::isGradeValid(int grade) {
  if (grade < 1)
    throw GradeTooHighException("Grade is too high");
  if (grade > 150)
    throw GradeTooLowException("Grade is too low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string &error)
    : std::range_error(error) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs) {
  out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return (out);
}
