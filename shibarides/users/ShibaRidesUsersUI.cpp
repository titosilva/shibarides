#include "ShibaRidesUsersUI.hpp"
#include "../ShibaUI.h"
#include <string>
#include <string.h>

bool UserSigninUI::show(Email &email, Senha &senha, CPF &cpf, Telefone &telefone,CodDeBanco &codbanco,
                        NumDeConta &numconta,NumDeAgencia &numagencia) throw (invalid_argument){
    int x,y;
    // Armazena a atual selecao do usuario
    unsigned int sel = 0;
    // Char array para armazenar as entradas do usuario
    char emailentry[80] = "", senhaentry[80] = "", cpfentry[11] = "", telefoneentry[12] = "", bancoentry[10] = "",
     contaentry[10] = "", agenciaentry[10] = "";

    while(true){
        // Constroi a tela
        clear();
        getmaxyx(stdscr, y, x);

        attron(COLOR_PAIR(2));
        char title[] = "Login";
        mvprintw(1, x/2-strlen(title)/2, "%s", title);

        char label1[] = "Email: ";
        mvprintw(y/2-8, x/5-strlen(label1)/2, "%s", label1);

        char label2[] = "Senha: ";
        mvprintw(y/2-7, x/5-strlen(label2)/2, "%s", label2);

        char label3[] = "CPF: ";
        mvprintw(y/2-6, x/5-strlen(label3)/2, "%s", label3);

        char label4[] = "Telefone: ";
        mvprintw(y/2-5, x/5-strlen(label4)/2, "%s", label4);

        char label5[] = "Codigo Do Banco: ";
        mvprintw(y/2-4, x/5-strlen(label5)/2, "%s", label5);

        char label6[] = "Numero da Conta: ";
        mvprintw(y/2-3, x/5-strlen(label6)/2, "%s", label6);

        char label7[] = "Numero da Agencia: ";
        mvprintw(y/2-2, x/5-strlen(label7)/2, "%s", label7);
        attroff(COLOR_PAIR(2));

        mvprintw(y/2-8, x/5+strlen(label1)/2+1, "%s", emailentry);
        mvprintw(y/2-7, x/5+strlen(label2)/2+1, "%s", senhaentry);
        mvprintw(y/2-6, x/5+strlen(label3)/2+1, "%s", cpfentry);
        mvprintw(y/2-5, x/5+strlen(label4)/2+1, "%s", telefoneentry);
        mvprintw(y/2-4, x/5+strlen(label5)/2+1, "%s", bancoentry);
        mvprintw(y/2-3, x/5+strlen(label6)/2+1, "%s", contaentry);
        mvprintw(y/2-2, x/5+strlen(label7)/2+1, "%s", agenciaentry);

        if(sel==7) attron(COLOR_PAIR(1));
        char opt1[] = "Sign In";
        mvprintw(y/2, x/5-strlen(opt1)/2, "%s", opt1);
        attroff(COLOR_PAIR(1));

        if(sel==8) attron(COLOR_PAIR(1));
        char opt2[] = "Cancel";
        mvprintw(y/2+1, x/5-strlen(opt2)/2, "%s", opt2);
        attroff(COLOR_PAIR(1));

        // Determina, a partir da seleção, o que o usuario esta selecionando
        switch(sel){
            case 0:
                move(y/2-8, x/5 + strlen(label1)/2 + strlen(emailentry) + 1);
                break;
            case 1:
                move(y/2-7, x/5 + strlen(label2)/2 + strlen(senhaentry) + 1);
                break;
            case 2:
                move(y/2-6, x/5 + strlen(label3)/2 + strlen(cpfentry) + 1);
                break;
            case 3:
                move(y/2-5, x/5 + strlen(label4)/2 + strlen(telefoneentry) + 1);
                break;
            case 4:
                move(y/2-4, x/5 + strlen(label5)/2 + strlen(bancoentry) + 1);
                break;
            case 5:
                move(y/2-3, x/5 + strlen(label6)/2 + strlen(contaentry) + 1);
                break;
            case 6:
                move(y/2-2, x/5 + strlen(label6)/2 + strlen(agenciaentry) + 1);
                break;
            case 9:
                move(0,0);
        }

        // Espera o usuario apertar algum botao
        while(!kbhit());

        // Analisa o botao apertado
        int c = getch();

        if (c==ARROWDOWN)
            sel = (sel+1)%10;
        else if(c==ARROWUP)
            sel = (sel-1)%10;
        else if(c==ENTER){
            switch(sel){
                case 0:
                case 1:
                    sel = (sel+1)%10;
                    break;
                case 2:
                    sel = (sel+1)%10;
                    break;
                case 3:
                    sel = (sel+1)%10;
                    break;
                case 4:
                    sel = (sel+1)%10;
                    break;
                case 5:
                    sel = (sel+1)%10;
                    break;
                case 6:
                    sel = (sel+1)%10;
                    break;
                case 7:
                    // Tentar o login
                    try{
                        email.setValue(emailentry);
                        senha.setValue(senhaentry);
                        cpf.setValue(cpfentry);
                        telefone.setValue(telefoneentry);
                        codbanco.setValue(bancoentry);
                        numconta.setValue(contaentry);
                        numagencia.setValue(agenciaentry);
                    }catch(const invalid_argument &e){
                        UserErrorUI::show(e.what());
                    }
                    break;
                case 8:
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
                else if(sel==2){
                    cpfentry[strlen(cpfentry)] = c;
                }
                else if(sel==3){
                    telefoneentry[strlen(telefoneentry)] = c;
                }
                else if(sel==4){
                    bancoentry[strlen(bancoentry)] = c;
                }
                else if(sel==5){
                    contaentry[strlen(contaentry)] = c;
                }
                else if(sel==6){
                    agenciaentry[strlen(agenciaentry)] = c;
                }
        }
    }

}
                        }
void UserErrorUI::show(string error){
    int x, y;
    clear();
    getmaxyx(stdscr, y, x);

    attron(COLOR_PAIR(1));
    char title[] = "ERROR";
    mvprintw(y/2-2, x/2-strlen(title)/2, "%s", title);
    mvprintw(y/2, x/2-strlen(error.c_str())/2, "%s", error.c_str());

    // Espera o usuario apertar algum botao
    while(!kbhit());

    attroff(COLOR_PAIR(1));
}
