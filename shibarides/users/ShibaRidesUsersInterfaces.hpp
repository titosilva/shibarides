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
    // Mostra tela de cadastramento
    virtual void signup(void) throw (runtime_error) = 0;

    // Permite dele��o de usu�rio
    // � retornado True caso a dele��o tenha sido efetivada
    // caso contr�rio,  retornado False
    virtual bool deletion(Email email) throw (runtime_error) = 0;

    // Seta a controladora
    virtual void setServiceController(IUserServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IUserView(){};
};

class IUserServ{
// M�todos abstratos puros que ser�o sorbeescritos pelas classes controladoras
public:
    // Realiza a edicao de um usuario
    // Retorna True caso seja poss�vel cadastrar o usu�rio, False caso contr�rio
    virtual bool registerUser(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf) throw (runtime_error)=0;

    // Dele��o de usu�rio
    // Retorna True caso a dele��o seja poss�vel
    virtual bool deleteUser(Email email) throw (runtime_error)=0;
};



#endif // SHIBARIDERSUSERINTERFACES_HPP_INCLUDED
