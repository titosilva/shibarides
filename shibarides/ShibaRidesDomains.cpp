#include "ShibaRidesDomains.hpp"
#include <iostream>
using namespace shibarides;

// Base class
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

// Domains

// Assento
void Assento::validate(std::string value) throw (std::invalid_argument){
    if(value!="D" && value!="T") throw (std::invalid_argument("Argument must be D or T"));
}

// Bagagem
void Bagagem::validate(std::string value) throw (std::invalid_argument){
    int number = std::stoi(value);
    if(number<0 || number>4) throw (std::invalid_argument("Argument must be 0, 1, 2, 3 or 4"));
}

// CodDeBanco
void CodDeBanco::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=3) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<3; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// CodDeCarona
void CodDeCarona::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=4) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<4; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// CodDeReserva
void CodDeReserva::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=5) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<5; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// Telefone
void Telefone::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=15) throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format"));

    for(int i=0; i<15; i++){
        // Verify the dashes
        if(i==2 || i==5){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 and dashes"));
        }
    }


    // Verify if there are 00's or a big 000000000
    int XX = std::stoi(value.substr(0,2));
    int YY = std::stoi(value.substr(3,2));
    int Z = std::stoi(value.substr(6,9));
    if(XX==0 || YY==0 || Z==0) throw (std::invalid_argument("Argument can't be zeroes"));
}


