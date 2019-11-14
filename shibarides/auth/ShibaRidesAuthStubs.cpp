#include "ShibaRidesAuthStubs.h"
#include <ncurses.h>

bool StubAuthServ::authenticate(Email email, Senha senha) throw (runtime_error){
    if(email.getValue() == this->TRIGGER_FAIL){
        return false;
    }else if(email.getValue() == this->TRIGGER_RUNTIME_ERROR){
        throw(runtime_error("Exception in authenticate method"));
    }else{
        return true;
    }
}
