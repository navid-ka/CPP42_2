/**********************************************************************/
/*                    | |                        (_)                  */
/*               _ __ | | _____ _   _  __ _ _ __  _                   */
/*              | '_ \| |/ / _ \ | | |/ _` | '_ \| |                  */
/*              | | | |   <  __/ |_| | (_| | | | | |                  */
/*              |_| |_|_|\_\___|\__, |\__,_|_| |_|_|                  */
/*                               __/ |                                */
/*                              |___/                                 */
/**********************************************************************/

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grades) : _name(name), _grades(grades) {
    std::string err = "Name is empty\n";
    try {
        if (this->_name.empty() || !this->_name)
            throw (err);
    }   catch (err) {
        ONLYPRINTFANS("Exception thown in " << err);
    }

}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    _name = copy.getName();
    _grades = copy.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    this->_name = rhs.getName();
    this->_grades = rhs.getGrade();
    return *this;
}

const std::string & Bureaucrat::getName() const {
    return (this->_name);
}


const int & Bureaucrat::getGrade() const {
    return (this->_grades);
}


