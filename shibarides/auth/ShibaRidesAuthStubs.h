#ifndef SHIBA_AUTH_STUBS_H__
#define SHIBA_AUTH_STUBS_H__

#include "ShibaRidesAuthInterfaces.h"

class StubAuthServ : public IAuthServ{
public:
    StubAuthServ(){
        TRIGGER_FAIL = "emailinvalido@gmail.com";
        TRIGGER_RUNTIME_ERROR = "runtime@gmail.com";
    }
    string TRIGGER_FAIL, TRIGGER_RUNTIME_ERROR;
    bool authenticate(Email email, Senha senha) throw (runtime_error);
};

#endif
