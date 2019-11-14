#ifndef SHIBARIDERSUSERCNTR_HPP_INCLUDED
#define SHIBARIDERSUSERCNTR_HPP_INCLUDED

#include "ShibaRidesUsersInterfaces.hpp"
#include "../domains/ShibaRidesDomains.hpp"

// Controladoras
// Classe que implementa a interface IUserView
class CntrUsersView;
// Classe que implementa a interface IUserServ
class CntrUsersServ;

class CntrUsersView : public IUserView{
private:
    // Referencia para o servidor
    IUserServ *service;
public:
    bool signin() throw (runtime_error);
    void setServiceController(IUserServ *);
};

class CntrUsersServ : public IUserServ{
public:
    bool edit(Email email, Senha senha, Nome nome, Telefone telefone, CPF cpf) throw(runtime_error);
};



#endif // SHIBARIDERSUSERCNTR_HPP_INCLUDED

