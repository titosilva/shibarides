#ifndef SHIBA_INTERFACE_AUTH_H__
#define SHIBA_INTERFACE_AUTH_H__

#include <stdexcept>
#include "../domains/ShibaRidesDomains.hpp"
using namespace std;
using namespace shibarides;

// Interfaces do subsistema de autenticaçao

// Interfaces
// Interface da camada de aplicação
class IAuthView;
// Interface da camada de serviço
class IAuthServ;

class IAuthView{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Mostra tela de login e realiza login
    virtual bool login(Email &email) throw (runtime_error) = 0;

    // Seta a controladora
    virtual void setServiceController(IAuthServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IAuthView(){};
};

class IAuthServ{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Realiza a autenticação de um usuario
    virtual bool authenticate(Email email, Senha senha) throw (runtime_error)=0;
};

#endif // SHIBA_INTERFACE_AUTH_H__
