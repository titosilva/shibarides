#ifndef SHIBA_AUTH_UI_H__
#define SHIBA_AUTH_UI_H__

#include "../ShibaUI.h"
#include "../domains/ShibaRidesDomains.hpp"
#include <stdexcept>
using namespace std;
using namespace shibarides;

// Telas a serem exibidas
// Tela de login
class AuthLoginUI;
// Tela de erro
class AuthErrorUI;

class AuthLoginUI{
public:
    // Retorna falso caso o usuario tenha desistido da operação
    // Retorna verdadeiro caso contrario e armazena em email e senha
    // os valores obtidos
    static bool show(Email &email, Senha &senha) throw (invalid_argument);
};

class AuthErrorUI{
public:
    // Mostra mensagem de erro
    static void show(string error);
};

#endif // SHIBA_AUTH_UI_H__
