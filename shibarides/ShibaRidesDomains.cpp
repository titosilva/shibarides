#include "ShibaRidesDomains.hpp"
#include <iostream>
#include <vector>
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

std::string Dominio::getValue() const{
    if(this->valueSet) return this->value;
    else return "";
}

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

void CPF::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=14) throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format"));

    // Verify string format
    for(int i=0; i<14; i++){
        if(i==3 || i==7){
            if(value.at(i)!='.') throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format (with dots and dashes)"));
        }else if(i==11){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format (with dots and dashes)"));
        }else{
            if(value.at(i)-'0'<0 || value.at(i)-'0'>9) throw (std::invalid_argument("Argument must have all digits 0-9, dots or dashes"));
        }
    }

    // Save the digits in a vector
    std::vector<int> digits;
    for(int i=0; i<14; i++){
        // Skip dots and dashes
        if(i==3 || i==7 || i==11) continue;

        digits.push_back(value.at(i)-'0');
    }

    // Multiĺy the first digits by a weight, in 10-2, corresponding to its position
    // and sum everything
    int sum = 0;
    for(int i=0; i<9; i++){
        sum += digits.at(i)*(10-i);
    }

   // Verify the first check digit
    if(sum%11>2){
        if(digits.at(9)!=(11-sum%11)) throw (std::invalid_argument("First check digit not correct"));
    }else{
        if(digits.at(9)!=0) throw (std::invalid_argument("First check digit not correct"));
    }
    // Multiĺy the first digits, including the first check digit,
    // by a weight, in 11-2, corresponding to its position
    // and sum everything
    sum = 0;
    for(int i=0; i<10; i++){
        sum += digits.at(i)*(11-i);
    }

    // Verify the second check digit
    if(sum%11>2){
        if(digits.at(10)!=(11-sum%11)) throw (std::invalid_argument("Second check digit not correct"));
    }else{
        if(digits.at(10)!=0) throw (std::invalid_argument("Second check digit not correct"));
    }
}

// NumDeAgencia
void NumDeAgencia::validate(std::string value) throw (std::invalid_argument){
    // Using Luhn's Algorithm
    if(value.size()!=6) throw(std::invalid_argument("Argument must be XXXX-Y format"));

    for(int i=0; i<6; i++){
        // Verify the dashes
        if(i==4){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XXXX-Y format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }

    // Luhn's Algorithm to verify the check digit
    std::vector<int> digits;

    // Store the digits in a vector
    for(int i=0; i<6; i++){
        // Skip the dash
        if(i==4) continue;
        digits.push_back(value.at(i)-'0');
    }

    // Double every second digit
    for(unsigned int i=0; i<digits.size()-1; i++){
        if(i%2==1) digits.at(i) = (digits.at(i)*2<10)? digits.at(i)*2 : digits.at(i)*2 - 9;
    }

    // check if the check digit is correct
    int sum = 0;
    for(unsigned int i=0; i<digits.size(); i++){
        sum += digits.at(i);
    }

    if(sum%10!=0) throw (std::invalid_argument("Invalid number"));
}

// NumDeConta
void NumDeConta::validate(std::string value) throw (std::invalid_argument){
    // Using Luhn's Algorithm
    if(value.size()!=8) throw(std::invalid_argument("Argument must be XXXXXX-Y format"));

    for(int i=0; i<8; i++){
        // Verify the dashes
        if(i==6){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XXXXXX-Y format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }

    // Luhn's Algorithm to verify the check digit
    std::vector<int> digits;

    // Store the digits in a vector
    for(int i=0; i<8; i++){
        // Skip the dash
        if(i==6) continue;
        digits.push_back(value.at(i)-'0');
    }

    // Double every second digit
    for(unsigned int i=0; i<digits.size()-1; i++){
        if(i%2==1) digits.at(i) = (digits.at(i)*2<10)? digits.at(i)*2 : digits.at(i)*2 - 9;
    }

    // check if the check digit is correct
    int sum = 0;
    for(unsigned int i=0; i<digits.size(); i++){
        sum += digits.at(i);
    }

    if(sum%10!=0) throw (std::invalid_argument("Invalid number"));
}

// Telefone
void Telefone::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=15) throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format"));

    for(int i=0; i<15; i++){
        // Verify the dashes
        if(i==2 || i==5){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }


    // Verify if there are 00's or a big 000000000
    int XX = std::stoi(value.substr(0,2));
    int YY = std::stoi(value.substr(3,2));
    int Z = std::stoi(value.substr(6,9));
    if(XX==0 || YY==0 || Z==0) throw (std::invalid_argument("Argument can't be zeroes"));
}


