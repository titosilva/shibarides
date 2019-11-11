#include "ShibaRidesAuthUI.h"
#include <string>
#include <string.h>

bool AuthLoginUI::show(Email &email, Senha &senha) throw (invalid_argument){
    int x,y;
    // Armazena a atual selecao do usuario
    unsigned int sel = 0;

    while(true){
        // Constroi a tela
        clear();
        getmaxyx(stdscr, y, x);

        attron(COLOR_PAIR(2));
        char title[] = "Login";
        mvprintw(1, x/2-strlen(title)/2, "%s", title);

        char label1[] = "Email: ";
        mvprintw(y/2-5, x/5-strlen(label1)/2, "%s", label1);

        char label2[] = "Senha: ";
        mvprintw(y/2-4, x/5-strlen(label2)/2, "%s", label2);
        attroff(COLOR_PAIR(2));

        // Coloca o cursor em outro lugar
        move(0,0);

        // Espera o usuario apertar algum botao
        while(!kbhit());

        // Analisa o botao apertado
        switch((int)getch()){
            case ARROWDOWN:
                sel = (sel+1)%3;
                break;
            case ARROWUP:
                sel = (sel-1)%3;
                break;
            case ENTER:
                break;
        }
    }

}

void AuthErrorUI::show(string error){

}
