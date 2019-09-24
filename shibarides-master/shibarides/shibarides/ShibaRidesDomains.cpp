#include "ShibaRidesDomains.hpp"
#include <iostream>
#include <string>
using namespace shibarides;

Dominio::Dominio(){
    this->valueSet = false;
    this->value = "";
}


void Dominio::setValue(std::string value) throw (std::invalid_argument){
    this->validate(value);
    this->value = value;
    this->valueSet = true;
}

std::string Dominio::getValue() const throw (std::exception){
    if(this->valueSet) return this->value;
    else throw std::exception();
}

void Dominio::validate(std::string value) throw (std::invalid_argument){}

void Assento::validate(std::string value) throw (std::invalid_argument){
    if(value!="D" && value!="T") throw (std::invalid_argument("Argument must be D or T"));
}

void Duracao::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string]>57 || value[tamanho_string]<48)
            throw (std::invalid_argument("Argument must be a inter"));
        if(value>48)
            throw (std::invalid_argument("Argument must be less than 48"));
    }
}

void Vagas::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4")){
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
    }
}

void Bagagem::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4")){
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
    }
}

void Estado::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value!=AC||value!=AL||value!=AP||value!=AM||value!=BA||value!=CE||value!=DF||
        value!=ES||value!=GO||value!=MA||value!=MT||value!=MS||value!=MG||value!=PA||value!=PB||
        value!=PR||value!=PE||value!=PI||value!=RJ||value!=RN||value!=RS||value!=RO||value!=RR||
        value!=SC||value!=SP||value!=SE||value!=TO) throw (std::invalid_argument("Argument inst a valid state"))
}
