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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

int main(void) {

    try {
        ShrubberyCreationForm A20("home");
        ShrubberyCreationForm A22("great");

        Bureaucrat John("John", 40);

        John.executeForm(A20);
        John.signForm(A20);
        John.executeForm(A20);

        John.signForm(A22);
        John.executeForm(A22);

        std::cout << A20 << std::endl;

        Bureaucrat Paul("Paul", 150);

        Paul.signForm(A20);

        RobotomyRequestForm C54("John");

        John.signForm(C54);
        John.executeForm(C54);

        std::cout << C54 << std::endl;

        PresidentialPardonForm Z89("John");

        John.signForm(Z89);
        John.executeForm(Z89);
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}
