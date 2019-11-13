#ifndef SHIBARIDERSUSERINTERFACES_HPP_INCLUDED
#define SHIBARIDERSUSERINTERFACES_HPP_INCLUDED

#include <stdexcept>
#include "../domains/ShibaRidesDomains.hpp"
using namespace std;
using namespace shibarides;

// Interfaces do subsistema de usuario

// Interfaces
// Interface da camada de aplicação
class IUserView;
// Interface da camada de serviço
class IUserServ;

class IUserView{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Mostra tela de cadastramento
    virtual void signup(void) throw (runtime_error) = 0;

    // Permite deleção de usuário
    // É retornado True caso a deleção tenha sido efetivada
    // caso contrário,  retornado False
    virtual bool deletion(Email email) throw (runtime_error) = 0;

    // Seta a controladora
    virtual void setServiceController(IUserServ *) = 0;

    // Metodo virtual destrutor
    virtual ~IUserView(){};
};

class IUserServ{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Realiza a edicao de um usuario
    // Retorna True caso seja possível cadastrar o usuário, False caso contrário
    virtual bool registerUser(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf) throw (runtime_error)=0;

    // Deleção de usuário
    // Retorna True caso a deleção seja possível
    virtual bool deleteUser(Email email) throw (runtime_error)=0;
};



#endif // SHIBARIDERSUSERINTERFACES_HPP_INCLUDED
