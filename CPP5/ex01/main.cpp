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
  // Bureaucrat
  try {
		Bureaucrat *ceo = new Bureaucrat("Teo", 2);
		Form form("permisos", 2, 2);
		ONLYPRINTFANS(ceo->getName());
		ONLYPRINTFANS(ceo->getGrade());
		ceo->signForm(form);
		delete ceo;
  } catch (std::exception &e) {
		ONLYPRINTFANS(e.what());
 }
 
  return (0);
}
