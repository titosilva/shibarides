#ifndef SHIBA_INIT_UI_H__
#define SHIBA_INIT_UI_H__

#include "../ShibaUI.h"

// Classe de Interface com o Usuario para o modulo de inicialização
// Tela inicial
class InitMainUI{
public:
    // Define os possiveis resultados das selecoes do usuario
    static const int INIT_MAIN_LOGIN=0, INIT_MAIN_SIGNUP=1, INIT_MAIN_EXIT=2, INIT_MAIN_LIST=3;
    // Constroi a tela e retorna o selecionado
    static int show();
};

// Tela apos o login
class InitLoggedUI{
public:
    // Constroi a tela e retorna o selecionado
    static int show();
};

#endif
