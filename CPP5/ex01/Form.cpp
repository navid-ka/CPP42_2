/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Form::Form(std::string name, int gradeSign, int gradeReqEx)
    : _name(name), _gradeSign(gradeSign), _gradeRequiredExec(gradeReqEx) {
    try {
        if (this->_name.empty())
            throw std::invalid_argument("name cannot be empty");
    } catch (std::invalid_argument &e) {
        ONLYPRINTFANS("Exception in constructor name validation" << e.what());
    }
    _isGradeSigned = false;

    try {
        isGradeValid(_gradeSign);
        isGradeValid(_gradeRequiredExec);
    } catch (GradeTooHighException &err) {
        ONLYPRINTFANS("Exception thrown in " << err.what());
    } catch (GradeTooLowException &err) {
        ONLYPRINTFANS("Exception thrown in " << err.what());
    }
}

Form::~Form() {}

Form::Form(const Form &copy)
    : _name(copy._name), _gradeSign(copy._gradeSign),
      _gradeRequiredExec(copy._gradeRequiredExec) {}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs)
        _isGradeSigned = rhs._isGradeSigned;
    return (*this);
}

const std::string &Form::getName() const { return (_name); }

int Form::getGradeSign() const { return (_gradeSign); }

int Form::getGradeReq() const { return (_gradeRequiredExec); }

bool Form::getIsGradeSigned() const { return (_isGradeSigned); }

void Form::beSigned(const Bureaucrat &bure) {
    if (bure.getGrade() <= _gradeSign) {
        _isGradeSigned = true;
    } else {
        throw GradeTooLowException(
            "The grade is not enough to sign the form\n");
    }
}

Form::GradeTooHighException::GradeTooHighException(const std::string &error)
    : std::range_error(error) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}

void Form::isGradeValid(int grade) {
    if (grade < 1)
        throw GradeTooHighException("Grade is too high");
    if (grade > 150)
        throw GradeTooLowException("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Form const &rhs) {
    out << rhs.getName() << ", form signing grade " << rhs.getGradeSign()
        << ", Execution grade " << rhs.getGradeReq() << " is";
    if (!rhs.getIsGradeSigned())
        out << " NOT";
    out << " signed" << std::endl;
    return (out);
}
