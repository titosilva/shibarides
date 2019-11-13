#include "ShibaRidesInitUI.h"
#include <string>
#include <string.h>
using namespace std;

int InitMainUI::show(){
    int x,y;
    // Armazena a atual selecao do usuario
    unsigned int sel = 0;

    while(true){
        // Constroi a tela
        clear();
        getmaxyx(stdscr, y, x);

        attron(COLOR_PAIR(2));
        char title[] = "Welcome to Shibarides!";
        mvprintw(y/2-3, x/2-strlen(title)/2, "%s", title);
        attroff(COLOR_PAIR(2));

        if(sel==0) attron(COLOR_PAIR(1));
        char opt1[] = "Login";
        mvprintw(y/2, x/2-strlen(opt1)/2, "%s", opt1);
        attroff(COLOR_PAIR(1));

        if(sel==1) attron(COLOR_PAIR(1));
        char opt2[] = "Sign Up";
        mvprintw(y/2+1, x/2-strlen(opt2)/2, "%s", opt2);
        attroff(COLOR_PAIR(1));

        if(sel==2) attron(COLOR_PAIR(1));
        char opt3[] = "Exit";
        mvprintw(y/2+2, x/2-strlen(opt3)/2, "%s", opt3);
        attroff(COLOR_PAIR(1));

        char info[] = "Use the arrow keys to select!";
        mvprintw(y-1, x/2-strlen(info)/2, "%s", info);

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
                switch(sel){
                    case 0:
                        return INIT_MAIN_LOGIN;
                        break;
                    case 1:
                        return INIT_MAIN_SIGNUP;
                        break;
                    case 2:
                        return INIT_MAIN_EXIT;
                        break;
                }
        }
    }
}

int InitLoggedUI::show(){

}
