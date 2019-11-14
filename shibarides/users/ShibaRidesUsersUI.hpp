#ifndef SHIBARIDERSUSERUI_HPP_INCLUDED
#define SHIBARIDERSUSERUI_HPP_INCLUDED

// Inclusão da biblioteca curses
#ifdef __unix__
    #include <ncurses.h>
#endif // __unix__

#ifdef _WIN32
    #include <curses.h>
#endif // _WIN32

#include "../domains/ShibaRidesDomains.hpp"
#include <stdexcept>
using namespace std;
using namespace shibarides;

// Telas a serem exibidas
// Tela de user
class UserLoginUI;
// Tela de erro
class UserErrorUI;

class UserLoginUI{
public:
    // Retorna falso caso o usuario tenha desistido da operação
    // Retorna verdadeiro caso contrario e armazena os valores obtidos
    static bool show(Email &email, Senha &senha, Nome &nome, Telefone &telefone, CPF &cpf) throw (invalid_argument);
};
class UserSigninUI{
public:
    // Retorna falso caso o usuario tenha desistido da operação
    // Retorna verdadeiro caso contrario e armazena os valores obtidos
    static bool show(Email &email, Senha &senha, Nome &nome, CPF &cpf, Telefone &telefone,CodDeBanco &codbanco,
                     NumDeConta &numconta,NumDeAgencia &numagencia) throw (invalid_argument);
};
class UserErrorUI{
public:
    // Mostra mensagem de erro
    static void show(string error);
};



#endif // SHIBARIDERSUSERUI_HPP_INCLUDED
