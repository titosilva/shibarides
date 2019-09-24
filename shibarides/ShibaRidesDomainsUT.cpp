#include "ShibaRidesDomainsUT.hpp"
#include <iostream>
using namespace shibarides;

TUDominio::TUDominio(){};

int TUDominio::run(){
    this->createDomain();
    this->successCase();
    this->failCase();
    this->destroyDomain();
    return this->state;
}

void TUDominio::genFailValues(){};
void TUDominio::genSuccessValues(){};

void TUDominio::createDomain(){};

void TUDominio::successCase(){
    for(int i=0; i<this->successValues.size(); i++){
        std::string val = this->successValues.at(i);
        try{
            this->domain->setValue(val);
            if(this->domain->getValue() != val) this->state = TUDominio::FAIL;
        }catch(std::exception e){
            this->state = TUDominio::FAIL;
        }
    }
}

void TUDominio::failCase(){
    for(int i=0; i<this->failValues.size(); i++){
        std::string val = this->failValues.at(i);
        try{
            this->domain->setValue(val);
            this->state = TUDominio::FAIL;
        }catch(std::exception e){
            if(this->domain->getValue()==val) this->state = TUDominio::FAIL;
        }
    }
}


void TUDominio::destroyDomain(){
    delete this->domain;
}

// Domains =============================================================

// Assento
TUAssento::TUAssento(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUAssento::createDomain(){
    this->domain = new Assento();
    this->state = TUDominio::SUCCESS;
}

void TUAssento::genFailValues(){
    this->failValues.push_back("A");
    this->failValues.push_back("B");
    this->failValues.push_back("C");
}

void TUAssento::genSuccessValues(){
    this->successValues.push_back("D");
    this->successValues.push_back("T");
}

// Bagagem
TUBagagem::TUBagagem(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUBagagem::createDomain(){
    this->domain = new Bagagem();
    this->state = TUDominio::SUCCESS;
}

void TUBagagem::genFailValues(){
    this->failValues.push_back("5");
    this->failValues.push_back("-1");
    this->failValues.push_back("ABACAXI");
}

void TUBagagem::genSuccessValues(){
    this->successValues.push_back("0");
    this->successValues.push_back("1");
    this->successValues.push_back("2");
    this->successValues.push_back("3");
    this->successValues.push_back("4");
}

// CodDeBanco
TUCodDeBanco::TUCodDeBanco(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeBanco::createDomain(){
    this->domain = new CodDeBanco();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeBanco::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("10000");
    this->failValues.push_back("22");
    this->failValues.push_back("");
}

void TUCodDeBanco::genSuccessValues(){
    this->successValues.push_back("999");
    this->successValues.push_back("000");
    this->successValues.push_back("123");
    this->successValues.push_back("456");
    this->successValues.push_back("789");
    this->successValues.push_back("156");
}

// CodDeCarona
TUCodDeCarona::TUCodDeCarona(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeCarona::createDomain(){
    this->domain = new CodDeCarona();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeCarona::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("10000");
    this->failValues.push_back("22");
    this->failValues.push_back("023");
    this->failValues.push_back("5");
    this->failValues.push_back("");
}

void TUCodDeCarona::genSuccessValues(){
    this->successValues.push_back("9999");
    this->successValues.push_back("0000");
    this->successValues.push_back("1234");
    this->successValues.push_back("4567");
    this->successValues.push_back("7890");
    this->successValues.push_back("1568");
}

// CodDeReserva
TUCodDeReserva::TUCodDeReserva(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeReserva::createDomain(){
    this->domain = new CodDeReserva();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeReserva::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("22");
    this->failValues.push_back("023");
    this->failValues.push_back("2");
    this->failValues.push_back("0235");
    this->failValues.push_back("");
}

void TUCodDeReserva::genSuccessValues(){
    this->successValues.push_back("99999");
    this->successValues.push_back("00000");
    this->successValues.push_back("12345");
    this->successValues.push_back("45678");
    this->successValues.push_back("78901");
    this->successValues.push_back("15674");
}

// Telefone
TUTelefone::TUTelefone(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUTelefone::createDomain(){
    this->domain = new Telefone();
    this->state = TUDominio::SUCCESS;
}

void TUTelefone::genFailValues(){
    this->failValues.push_back("5561912345678");
    this->failValues.push_back("ab");
    this->failValues.push_back("55-61912345678");
    this->failValues.push_back("5561-912345678");
    this->failValues.push_back("55 61 912345678");
    this->failValues.push_back("556191234567a");
    this->failValues.push_back("b561912345678");
    this->failValues.push_back("abc");
    this->failValues.push_back("00-61-912345678");
    this->failValues.push_back("55-00-912345678");
    this->failValues.push_back("55-61-000000000");
}

void TUTelefone::genSuccessValues(){
    this->successValues.push_back("55-61-912345678");
    this->successValues.push_back("10-57-982345679");
}
