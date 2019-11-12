#include <iostream>
using namespace std;

#include "ShibaRidesInitUI.h"
#include "../auth/ShibaRidesAuth.h"
#include "../domains/ShibaRidesDomains.hpp"

int main(){
    IAuthView *authview = new CntrAuthView();
    IAuthServ *authserv = new CntrAuthServ();

    authview->setServiceController(authserv);

    // Inicia o curses
    initscr();
    cbreak();
    noecho();
    //nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    // Inicia alguns pares de cores
    start_color();
    init_pair(1, COLOR_RED  , COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    // Mostra tela principal
    Email email;
    // controla o loop
    bool cntr=true;
    while(cntr){
        switch(InitMainUI::show()){
            case InitMainUI::INIT_MAIN_LOGIN:
                cntr = !authview->login(email);
                break;
            case InitMainUI::INIT_MAIN_SIGNUP:
                break;
            case InitMainUI::INIT_MAIN_EXIT:
                cntr = false;
                break;
        }
    }

    endwin();
    return 0;
}
