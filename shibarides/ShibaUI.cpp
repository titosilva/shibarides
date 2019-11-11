#include "ShibaUI.h"

// Implementação da funcao kbhit()
// Função para obter eventos de key press
int kbhit(void){
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}
