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

int main(void)
{
    //***TEST TRY CATCH***
    try {
        if (1 == 2) {
            ONLYPRINTNOFANS("True", "", "");
        } else {
            throw (404);
        }
    } catch (int e) {
        ONLYPRINTFANS("Exception thown in " << e);
    }
    //Bureaucrat


    return (0);
}