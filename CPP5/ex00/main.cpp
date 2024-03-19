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
#include <string>

int main(void) {
  //***TEST TRY CATCH***
  try {
    if (1 == 2) {
      ONLYPRINTNOFANS("True", "", "");
    } else {
      throw(404);
    }
  } catch (int e) {
    ONLYPRINTFANS("Exception thown in " << e);
  }
  // Bureaucra
  Bureaucrat *ceo = new Bureaucrat("Teo", 2);
  std::cout << &((class Bureaucrat *)0)->getName() << std::endl;
  ONLYPRINTFANS(ceo->getName());
  ceo->incrementGrade(1);
  ceo->incrementGrade(1);
  ceo->incrementGrade(1);
  ONLYPRINTFANS(ceo->getGrade());
  ceo->decrementGrade(10);
  ONLYPRINTFANS(ceo->getGrade());

  delete ceo;
  return (0);
}
