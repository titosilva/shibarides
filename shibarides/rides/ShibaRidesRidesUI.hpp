#ifndef SHIBARIDERSRIDEUI_HPP_INCLUDED
#define SHIBARIDERSRIDEUI_HPP_INCLUDED

// Inclusão da biblioteca curses
#ifdef __unix__
    #include <ncurses.h>
#endif // __unix__

#ifdef _WIN32
#endif // _WIN32

#include "../domains/ShibaRidesDomains.hpp"
#include <stdexcept>
using namespace std;
using namespace shibarides;

// Telas a serem exibidas
// Tela de carona
class RideLoginUI;
// Tela de erro
class RideErrorUI;

class RideUI{
public:
    // Retorna falso caso o usuario tenha desistido da operação
    // Retorna verdadeiro caso contrario e armazena os valores obtidos

    static bool showRide(CodDeCarona codcarona, Cidade cidorigem, Cidade ciddestino,
                         Preco preco, Estado estorigem, Estado estdestino,Data data,
                         Duracao duracao, Vagas vagas) throw (invalid_argument);
    static bool showReserve(CodDeReserva codreserva, Assento assento, Bagagem bagagem) throw(runtime_error);
};

class RideErrorUI{
public:
    // Mostra mensagem de erro
    static void show(string error);
};




#endif // SHIBARIDERSRIDEUI_HPP_INCLUDED
