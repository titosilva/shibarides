#ifndef SHIBA_AUTH_CNTRL_H__
#define SHIBA_AUTH_CNTRL_H__

#include "ShibaRidesAuthInterfaces.h"
#include "../domains/ShibaRidesDomains.hpp"

// Controladoras
// Classe que implementa a interface IAuthView
class CntrAuthView;
// Classe que implementa a interface IAuthServ
class CntrAuthServ;

class CntrAuthView : public IAuthView{
private:
    // Referencia para o servidor
    IAuthServ *service;
public:
    bool login(Email &email) throw (runtime_error);
    void setServiceController(IAuthServ *);
};

class CntrAuthServ : public IAuthServ{
public:
    bool authenticate(Email email, Senha senha) throw(runtime_error);
};

#endif // SHIBA_AUTH_CNTRL_H__
