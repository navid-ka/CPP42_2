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
#include "Form.hpp"
#include <iostream>



Form::GradeTooHighException::GradeTooHighException(
    const std::string &error)
    : std::range_error(error) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}
