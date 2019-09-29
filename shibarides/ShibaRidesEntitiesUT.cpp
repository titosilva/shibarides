#include "ShibaRidesEntitiesUT.hpp"
using namespace shibarides;

// Base Class

TUEntidade::TUEntidade(){
    this->state = TUEntidade::SUCCESS;
}

int TUEntidade::run(){
    this->createEntity();
    this->testMethods();
    this->destroyEntity();
    return this->state;
}

// Usuario
void TUUsuario::createEntity(){
    this->usuario = new Usuario();
}

void TUUsuario::testMethods(){
    Nome nome;

    // Set a valid name to nome
    nome.setValue("Teste");

    try{
        this->usuario->setNome(nome);

        if(this->usuario->getNome().getValue()!=nome.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }
}

void TUUsuario::destroyEntity(){
    delete this->usuario;
}
