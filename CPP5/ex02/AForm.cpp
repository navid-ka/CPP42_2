/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm(std::string name, int gradeSign, int gradeReqEx)
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

AForm::~AForm() {}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _gradeSign(copy._gradeSign),
      _gradeRequiredExec(copy._gradeRequiredExec) {}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs)
        _isGradeSigned = rhs._isGradeSigned;
    return (*this);
}

const std::string &AForm::getName() const { return (_name); }

int AForm::getGradeSign() const { return (_gradeSign); }

int AForm::getGradeReq() const { return (_gradeRequiredExec); }

bool AForm::getIsGradeSigned() const { return (_isGradeSigned); }

void AForm::beSigned(const Bureaucrat &bure) {
    if (bure.getGrade() <= _gradeSign) {
        _isGradeSigned = true;
    } else {
        throw GradeTooLowException(
            "The grade is not enough to sign the form\n");
    }
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &error)
    : std::range_error(error) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}

void AForm::isGradeValid(int grade) {
    if (grade < 1)
        throw GradeTooHighException("Grade is too high");
    if (grade > 150)
        throw GradeTooLowException("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, AForm const &rhs) {
    out << rhs.getName() << ", form signing grade " << rhs.getGradeSign()
        << ", Execution grade " << rhs.getGradeReq() << " is";
    if (!rhs.getIsGradeSigned())
        out << " NOT";
    out << " signed" << std::endl;
    return (out);
}
