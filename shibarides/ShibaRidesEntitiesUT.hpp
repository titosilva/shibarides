#ifndef SHIBARIDESENTITIESUT_HPP_INCLUDED
#define SHIBARIDESENTITIESUT_HPP_INCLUDED

#include "ShibaRidesEntities.hpp"
#include "ShibaRidesDomains.hpp"
#include <vector>

namespace shibarides{

class TUEntidade{
public:
    TUEntidade();
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    int state;
private:
    virtual void createUsuario()=0;
    virtual void testMethods()=0;
    virtual void destroyUsuario()=0;
};

class TUUsuario : public TUEntidade{
private:
    Usuario *usuario;
private:
    void createUsuario();
    void testMethods();
    void destroyUsuario();
};

class TUConta : public TUEntidade{
private:
    Conta *conta;
private:
    void createConta();
    void testMethods();
    void destroyConta();
};

class TUReserva : public TUEntidade{
private:
    Reserva *reserva;
private:
    void createReserva();
    void testMethods();
    void destroyReserva();
};

};
#endif // SHIBARIDESENTITIES_HPP_INCLUDED
