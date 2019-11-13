#ifndef SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED
#define SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED

#include <stdexcept>
#include "../domains/ShibaRidesDomains.hpp"
using namespace std;
using namespace shibarides;

// Interfaces do subsistema de carona

// Interfaces
// Interface da camada de aplica��o
class IRideView;
// Interface da camada de servi�o
class IRideServ;

class IRideView{
// M�todos abstratos puros que ser�o sorbeescritos pelas classes controladoras
public:
    // Seta a controladora
    virtual void setServiceController(IRideServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IRideView(){};
};

class IRideServ{
// M�todos abstratos puros que ser�o sorbeescritos pelas classes controladoras
public:
    // Realiza a criacao de uma carona
    virtual bool ride(CodDeCarona codcarona, Cidade cidorigem, Cidade ciddestino,
                      Preco preco, Estado estorigem, Estado estdestino,Data data,
                      Duracao duracao, Vagas vagas) throw (runtime_error)=0;

    // Realiza a criacao de uma reserva
    virtual bool reserve(CodDeReserva codreserva, Assento assento, Bagagem bagagem) throw (runtime_error)=0;
};


#endif // SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED
