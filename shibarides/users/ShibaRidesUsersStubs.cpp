#include "ShibaRidesUsersStubs.hpp"
#include <curses.h>

bool StubUsersServ::authenticate(Nome nome, Email email, Senha senha, Telefone telefone, CPF cpf,
                                 CodDeBanco banco, NumDeConta conta, NumDeAgencia agencia) throw (runtime_error){
    mvprintw(0,0,"ok");
    if(email.getValue() == "emailvalido@gmail.com" && senha.getValue() == "Val1d" && cpf.getValue() == "14745086695"
    && telefone.getValue() == "556193955666" && banco.getValue() == "333" && conta.getValue() == "9999996" && agencia.getValue()=="99994"){
        return true;
    }
    else
        return false;
}
