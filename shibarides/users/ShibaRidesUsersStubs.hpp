#ifndef SHIBARIDERSUSERSTUBS_HPP_INCLUDED
#define SHIBARIDERSUSERSTUBS_HPP_INCLUDED

#include "ShibaRidesUsersInterfaces.hpp"

class StubUsersServ : public IUserServ{
public:
    StubUsersServ(){
        TRIGGER_FAIL = "emailinvalido@gmail.com";
        TRIGGER_RUNTIME_ERROR = "runtime@gmail.com";
    }
    string TRIGGER_FAIL, TRIGGER_RUNTIME_ERROR;
    bool authenticate(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf, CodDeBanco banco, NumDeConta conta,
                      NumDeAgencia agencia) throw (runtime_error);
};

#endif // SHIBARIDERSUSERSTUBS_HPP_INCLUDED
