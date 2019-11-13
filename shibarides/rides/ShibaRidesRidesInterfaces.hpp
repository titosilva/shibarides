#ifndef SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED
#define SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED

#include <stdexcept>
#include "../domains/ShibaRidesDomains.hpp"
#include <vector>
using namespace std;
using namespace shibarides;

// Interfaces do subsistema de carona

// Interfaces
// Interface da camada de aplicação
class IRidesView;
// Interface da camada de serviço
class IRidesServ;

class IRidesView{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Tela de consulta a caronas
    virtual void queryRides(void) throw (runtime_error)=0;

    // Reserva de carona
    // Deve ser passada uma referencia ao email do usuario
    // para que a reserva seja cadastrada no sistema
    virtual void reserveRide(Email email) throw (runtime_error)=0;

    // Cadastro de carona
    // Deve ser passada uma referencia ao email do usuario
    // para que a carona seja cadastrada no sistema
    virtual void registerRide(Email email) throw (runtime_error)=0;

    // Lista as reservas associadas ao usuario
    // Aqui, tambem sera possivel descadastrar uma carona
    virtual void listUserReservedRides(Email email) throw (runtime_error)=0;

    // Lista as caronas ofertadas pelo usuario
    // Aqui, tambem sera possivel descadastrar uma carona
    virtual void listUserOfferedRides(Email email) throw (runtime_error)=0;

    // Seta a controladora
    virtual void setServiceController(IRidesServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IRideView(){};
};

class IRidesServ{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Retorna as caronas com as informações dadas
    // Caso não sejam encontradas caronas, retorna False
    // Caso sejam encontradas, retorna True e armazena objetos do tipo carona
    // no vetor caronavec
    virtual bool getRides(Estado estorigem, Cidade cidorigem, Estado estdest, Cidade ciddest, Data leaving,
                           std::vector<Carona> &caronavec) throw (runtime_error)=0;

    // Realiza o cadastramento de uma nova carona associada ao usuario com email email
    virtual bool createRide(Email email, CodDeCarona cod, Estado estorigem, Cidade cidorigem, Estado estdest,
                            Cidade ciddest,
                            Data leaving, Duracao time, Vagas available, Preco price) throw (runtime_error)=0;

    // Retorna as reservas associadas ao usuario com email email
    virtual bool getReserves(Email email, std::vector<Reserva> &reservesvec) throw (runtime_error)=0;

    // Retorna as caronas ofertadas pelo usuario com email email
    virtual bool getOfferedRides(Email email, std::vector<Carona> &caronavec) throw (runtime_error)=0;

    // Realiza a criacao de uma reserva
    virtual bool reserveRide(CodDeReserva codreserva, Assento assento, Bagagem bagagem) throw (runtime_error)=0;
};


#endif // SHIBARIDERSRIDEINTERFACE_HPP_INCLUDED
