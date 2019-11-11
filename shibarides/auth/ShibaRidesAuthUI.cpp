#include "ShibaRidesAuthUI.h"

bool AuthLoginUI::show(Email &email, Senha &senha) throw (invalid_argument){
    // Constroi a tela de login
    mvprintw(0, 0, "Login");

    mvprintw(3,10, "Email: ");
    mvprintw(3,11, "Senha: ");


}

void AuthErrorUI::show(string error){

}
