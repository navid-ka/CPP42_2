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
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat	bob("Bob", 2);
		Bureaucrat	bill("Bill", 132);

		Bureaucrat & bill_ref = bill;

		Form		a("A13", 4, 6);
		Form		b("B97", 146, 135);
		Form		c("E01", 1, 1);
		// Sign forms
		std::cout << std::endl;
		std::cout << "-------SIGN:-------- KO" << std::endl;

		// Sign KO
		std::cout << "SIGN KO:" << std::endl;
		bill_ref.signForm(a);
		std::cout << a << std::endl;
		std::cout << std::endl;

		std::cout << "SIGN KO:" << std::endl;
		bob.signForm(c);
		std::cout << c << std::endl;
		std::cout << std::endl;

		std::cout << "-------SIGN:-------- KO" << std::endl;
		// Sign OK
		std::cout << "SIGN OK:" << std::endl;
		bob.signForm(b);
		std::cout << b << std::endl;

		// Sign OK
		std::cout << "SIGN OK:" << std::endl;
		bill.signForm(b);
		std::cout << b << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	
  return (0);
}
