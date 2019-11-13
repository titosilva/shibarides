#ifndef SHIBARIDERSUSERCNTR_HPP_INCLUDED
#define SHIBARIDERSUSERCNTR_HPP_INCLUDED

#include "ShibaRidesUserInterfaces.h"
#include "../domains/ShibaRidesDomains.hpp"

// Controladoras
// Classe que implementa a interface IUserView
class CntrUserView;
// Classe que implementa a interface IUserServ
class CntrUserServ;

class CntrUserView : public IUserView{
private:
    // Referencia para o servidor
    IUserServ *service;
public:
    bool edit(Email &email) throw (runtime_error);
    void setServiceController(IUserServ *);
};

class CntrUserServ : public IUserServ{
public:
    bool edit(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf) throw(runtime_error);
};



#endif // SHIBARIDERSUSERCNTR_HPP_INCLUDED
