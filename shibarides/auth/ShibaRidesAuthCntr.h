#ifndef SHIBA_CNTRL_H__
#define SHIBA_CNTRL_H__

#include "ShibaRidesAuthInterfaces.h"
#include "../domains/ShibaRidesDomains.hpp"

// Classe que implementa a interface IAuthView
class CntrAuthView;
// Classe que implementa a interface IAuthServ
class CntrAuthServ;

class CntrAuthView : public IAuthView{
private:
    // Referencia para o servidor
    IAuthServ *service;
public:
    bool login() throw (runtime_error);
    void setServiceController(IAuthView *);
};

class CntrAuthServ : publi IAuthServ{
public:
    bool authenticate(Email email, Senha senha) throw(runtime_error);
}

class CntrAuthServ : public IAuthServ{
public:
    // Realiza a autenticação de um usuario
    bool authenticate(Email email, Senha senha) throw (runtime_error)=0;
};

#endif // SHIBA_CNTRL_H__
