#ifndef SHIBARIDERSUSERINTERFACES_HPP_INCLUDED
#define SHIBARIDERSUSERINTERFACES_HPP_INCLUDED

#include <stdexcept>
#include "../domains/ShibaRidesDomains.hpp"
using namespace std;
using namespace shibarides;

// Interfaces do subsistema de usuario

// Interfaces
// Interface da camada de aplica��o
class IUserView;
// Interface da camada de servi�o
class IUserServ;

class IUserView{
// M�todos abstratos puros que ser�o sorbeescritos pelas classes controladoras
public:
    // Cadastro de usu�rio
    virtual bool signin() throw (runtime_error) = 0;
    // Seta a controladora
    virtual void setServiceController(IUserServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IUserView(){};
};

class IUserServ{
// M�todos abstratos puros que ser�o sorbeescritos pelas classes controladoras
public:
    // Realiza a edicao de um usuario
    virtual bool edit(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf) throw (runtime_error)=0;
};



#endif // SHIBARIDERSUSERINTERFACES_HPP_INCLUDED
