#ifndef SHIBARIDESENTITIESUT_HPP_INCLUDED
#define SHIBARIDESENTITIESUT_HPP_INCLUDED

#include "ShibaRidesEntities.hpp"
#include "ShibaRidesDomains.hpp"
#include <vector>

namespace shibarides{

class TUUsuario{
public:
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Usuario *usuario;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:

    void genFailValues();
    void genSuccessValues();

    void createUsuario();
    void successCase();
    void failCase();
    void destroyUsuario();
};

class TUReserva{
public:
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Reserva *reserva;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:
    void genFailValues();
    void genSuccessValues();

    void createReserva();
    void successCase();
    void failCase();
    void destroyReserva();
};

class TUCarona{
public:
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Carona *carona;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:

    void genFailValues();
    void genSuccessValues();

    void createCarona();
    void successCase();
    void failCase();
    void destroyCarona();
};

class TUConta{
public:
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Conta *conta;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:

    void genFailValues();
    void genSuccessValues();

    void createConta();
    void successCase();
    void failCase();
    void destroyConta();
};

};
#endif // SHIBARIDESENTITIES_HPP_INCLUDED
