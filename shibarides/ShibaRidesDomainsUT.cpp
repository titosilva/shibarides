#include "ShibaRidesDomainsUT.hpp"
using namespace shibarides;

TUDominio::TUDominio(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

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
    std::vector<std::string>::iterator ptr;

    for(ptr = this->successValues.begin(); ptr<this->successValues.end(); ptr++){
        try{
            this->domain->setValue(*ptr);
            if(this->domain->getValue() != *ptr) this->state = TUDominio::FAIL;
        }catch(std::exception e){
            this->state = TUDominio::FAIL;
        }
    }
}

void TUDominio::failCase(){
     std::vector<std::string>::iterator ptr;

    for(ptr = this->failValues.begin(); ptr<this->failValues.end(); ptr++){
        try{
            this->domain->setValue(*ptr);
            this->state = TUDominio::FAIL;
        }catch(std::exception e){
            return;
        }
    }
}


void TUDominio::destroyDomain(){
    delete this->domain;
}

// =========================================================================

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
    this->failValues.push_back("D");
    this->failValues.push_back("T");
}
