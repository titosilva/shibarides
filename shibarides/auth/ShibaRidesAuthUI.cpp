#include "ShibaRidesAuthUI.h"
#include <string>
#include <string.h>

bool AuthLoginUI::show(Email &email, Senha &senha) throw (invalid_argument){
    int x,y;
    // Armazena a atual selecao do usuario
    unsigned int sel = 0;
    // Char array para armazenar as entradas do usuario
    char emailentry[80] = "", senhaentry[80] = "";

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

        mvprintw(y/2-5, x/5+strlen(label1)/2+1, "%s", emailentry);
        mvprintw(y/2-4, x/5+strlen(label2)/2+1, "%s", senhaentry);

        if(sel==2) attron(COLOR_PAIR(1));
        char opt1[] = "Login";
        mvprintw(y/2, x/5-strlen(opt1)/2, "%s", opt1);
        attroff(COLOR_PAIR(1));

        if(sel==3) attron(COLOR_PAIR(1));
        char opt2[] = "Cancel";
        mvprintw(y/2+1, x/5-strlen(opt2)/2, "%s", opt2);
        attroff(COLOR_PAIR(1));

        // Determina, a partir da seleção, o que o usuario esta selecionando
        switch(sel){
            case 0:
                move(y/2-5, x/5 + strlen(label1)/2 + strlen(emailentry) + 1);
                break;
            case 1:
                move(y/2-4, x/5 + strlen(label2)/2 + strlen(senhaentry) + 1);
                break;
            case 2:
            case 3:
                move(0,0);
        }

        // Espera o usuario apertar algum botao
        while(!kbhit());

        // Analisa o botao apertado
        int c = getch();

        if (c==ARROWDOWN)
            sel = (sel+1)%4;
        else if(c==ARROWUP)
            sel = (sel-1)%4;
        else if(c==ENTER){
            switch(sel){
                case 0:
                case 1:
                    sel = (sel+1)%4;
                    break;
                case 2:
                    // Tentar o login
                    try{
                        email.setValue(emailentry);
                        senha.setValue(senhaentry);
                    }catch(const invalid_argument &e){
                        AuthErrorUI::show("Invalid argument!");
                    }
                    break;
                case 3:
                    // Cancelar
                    return false;
                    break;
            }
        }else{
            if(isalpha(c) || isdigit(c) || c=='@' || c=='.'){
                if(sel==0){
                    emailentry[strlen(emailentry)] = c;
                }else if(sel==1){
                    senhaentry[strlen(senhaentry)] = c;
                }
            }else if(c==0x7f){
                if(sel==0){
                    emailentry[strlen(emailentry)-1] = '\0';
                }else if(sel==1){
                    senhaentry[strlen(senhaentry)-1] = '\0';
                }
            }
        }
    }

}

void AuthErrorUI::show(string error){
    int x, y;
    clear();
    getmaxyx(stdscr, y, x);

    attron(COLOR_PAIR(1));
    char title[] = "ERROR";
    mvprintw(y/2-2, x/2-strlen(title)/2, "%s", title);
    mvprintw(y/2, x/2-strlen(error.c_str())/2, "%s", error.c_str());
    while(!kbhit());

    attroff(COLOR_PAIR(1));
}
