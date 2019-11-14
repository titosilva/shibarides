#include "ShibaRidesAuthStubs.h"
#include <ncurses.h>

bool StubAuthServ::authenticate(Email email, Senha senha) throw (runtime_error){
    mvprintw(0,0,"ok");
    if(email.getValue() == StubAuthServ::TRIGGER_FAIL){

        return false;
    }else if(email.getValue() == StubAuthServ::TRIGGER_RUNTIME_ERROR){
        throw(runtime_error("Exception in authenticate method"));
    }else{
        return true;
    }
}
