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

//============================================================================
void TUDuracao::createDomain(){
    this->domain = new Duracao();
    this->state = TUDominio::SUCCESS;
}

void TUDuracao::genFailValues(){
    this->failValues.push_back("asdaw");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
}

void TUDuracao::genSuccessValues(){
    this->failValues.push_back("123");
    this->failValues.push_back("03");
}

//============================================================================
void TUVagas::createDomain(){
    this->domain = new Vagas();
    this->state = TUDominio::SUCCESS;
}

void TUVagas::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("5");
}

void TUVagas::genSuccessValues(){
    this->failValues.push_back("1");
    this->failValues.push_back("0");
}
//============================================================================
void TUBagagem::createDomain(){
    this->domain = new Bagagem();
    this->state = TUDominio::SUCCESS;
}

void TUBagagem::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("5");
}

void TUBagagem::genSuccessValues(){
    this->failValues.push_back("1");
    this->failValues.push_back("0");
}

//============================================================================

void TUBagagem::createDomain(){
    this->domain = new Bagagem();
    this->state = TUDominio::SUCCESS;
}

void TUBagagem::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("5");
}

void TUBagagem::genSuccessValues(){
    this->failValues.push_back("DF");
    this->failValues.push_back("MG");
}
