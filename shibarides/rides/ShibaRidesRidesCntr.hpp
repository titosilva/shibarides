#ifndef SHIBARIDERSRIDECNTR_HPP_INCLUDED
#define SHIBARIDERSRIDECNTR_HPP_INCLUDED

#include "ShibaRidesRideInterfaces.h"
#include "../domains/ShibaRidesDomains.hpp"

// Controladoras
// Classe que implementa a interface IRideView
class CntrRideView;
// Classe que implementa a interface IRideServ
class CntrRideServ;

class CntrRideView : public IRideView{
private:
    // Referencia para o servidor
    IRideServ *service;
public:
    //bool login(Email &email) throw (runtime_error);
    void setServiceController(IRideServ *);
};

class CntrRideServ : public IRideServ{
public:
    bool createRide(CodDeCarona codcarona, Cidade cidorigem, Cidade ciddestino,
                      Preco preco, Estado estorigem, Estado estdestino,Data data,
                      Duracao duracao, Vagas vagas) throw(runtime_error);

    bool createReserve(CodDeReserva codreserva, Assento assento, Bagagem bagagem) throw(runtime_error);
};



#endif // SHIBARIDERSRIDECNTR_HPP_INCLUDED
