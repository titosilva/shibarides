#include "ShibaRidesDomains.hpp"
#include <iostream>
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
