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
#include <string>

int main(void) {
    try {
        Bureaucrat bob("Bob", 2);
        Bureaucrat bill("Bill", 132);

        // Abstract classes can't be initialized
        // AForm a("A13", 4, 6);
        // AForm b("B97", 146, 135);
        // AForm c("E01", 1, 150);
        // Sign forms
        std::cout << std::endl;
        std::cout << "-------SIGN:-------- KO" << std::endl;

        // Sign KO

        std::cout << "SIGN KO:" << std::endl;

        std::cout << "-------SIGN:-------- KO" << std::endl;
        // Sign OK
        std::cout << "SIGN OK:" << std::endl;
        // Sign OK
        std::cout << "SIGN OK:" << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return (0);
}
