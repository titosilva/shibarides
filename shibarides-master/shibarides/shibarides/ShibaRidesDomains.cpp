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
    int valor = ::atoi(value.c_str());
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string]>57 || value[tamanho_string]<48)
            throw (std::invalid_argument("Argument must be a inter"));
        if(valor>48)
            throw (std::invalid_argument("Argument must be less than 48"));
    }
}

void Vagas::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
}

void Bagagem::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
}

void Estado::validate(std::string value) throw (std::invalid_argument){
    if (value!="AC"||value!="AL"||value!="AP"||value!="AM"||value!="BA"||value!="CE"||value!="DF"||
        value!="ES"||value!="GO"||value!="MA"||value!="MT"||value!="MS"||value!="MG"||value!="PA"||value!="PB"||
        value!="PR"||value!="PE"||value!="PI"||value!="RJ"||value!="RN"||value!="RS"||value!="RO"||value!="RR"||
        value!="SC"||value!="SP"||value!="SE"||value!="TO") throw (std::invalid_argument("Argument inst a valid state"));
}

void Nome::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_letter = 0;
    if (value.length()>20)throw (std::invalid_argument("Argument must have less than 21 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if((value[tamanho_string] >= 64 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           value[tamanho_string] == 46 || value[tamanho_string] == 32){}
            else {throw (std::invalid_argument("Argument must be letters, spaces or comas"));}
        if(value[tamanho_string] == 32 && value[tamanho_string+1] == 32)
            throw (std::invalid_argument("cant have two spaces together"));
        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the name"));

    }
}

void Cidade::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_letter = 0;
    if (value.length()>10)throw (std::invalid_argument("Argument must have less than 11 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if((value[tamanho_string] >= 64 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           value[tamanho_string] == 46 || value[tamanho_string] == 32){}
            else {throw (std::invalid_argument("Argument must be letters, spaces or comas"));}
        if(value[tamanho_string] == 32 && value[tamanho_string+1] == 32)
            throw (std::invalid_argument("cant have two spaces together"));
        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the name"));

    }
}

void Preco::validate(std::string value) throw (std::invalid_argument){
    double valor = ::atof(value.c_str());
    if (valor < 0 || valor > 5000) throw (std::invalid_argument("Argument must be bigger than 0,00 and smaller than 5000,01"));
}

void Email::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int tamanho_nome = 0;
    int tamanho_dominio = 0;
    int check_arroba = 0;
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] == 64)
            check_arroba++;
        if(check_arroba == 0)throw (std::invalid_argument("need at least one @ in the name"));
        if(check_arroba > 1) throw (std::invalid_argument("cant have more than 1 @"));

        if(value[tamanho_string] == 64){
            tamanho_nome = tamanho_string+1;
            tamanho_dominio = value.length()-tamanho_string+1;
        }
        if((value[tamanho_string] >= 64 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           value[tamanho_string] == 46){}
            else {throw (std::invalid_argument("Argument must be letters or comas"));}
        if(value[tamanho_string] == 46 && value[tamanho_string+1] == 46)
            throw (std::invalid_argument("cant have two comas together"));
    }

    if (tamanho_nome > 10 || tamanho_dominio > 10)throw (std::invalid_argument("Argument must have less than 11 chars"));
}

void Senha::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_repetidas = 0;
    int check_letter = 0;
    int check_num = 0;
    if (value.length()>5)throw (std::invalid_argument("Argument must have less than 6 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if((value[tamanho_string] >= 65 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           (value[tamanho_string] >= 48 && value[tamanho_string] <= 57) || (value[tamanho_string] >= 35 && value[tamanho_string] <= 38)){
           }
        else {throw (std::invalid_argument("Argument must be letters,numbers,%,$,# or &"));}

        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the password"));

        if((value[tamanho_string] >= 48 && value[tamanho_string] <= 57))
            check_num++;
        if(check_num == 0)throw (std::invalid_argument("need at least one number in the password"));

        for(check_repetidas = tamanho_string+1; check_repetidas < value.length();check_repetidas++){
            if(value[tamanho_string] == value[check_repetidas])
                throw (std::invalid_argument("cant have two equal chars in the password"));
        }

    }
}

void Data::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int valor = (int)value[9]+(int)value[8]*10;
    if (value.length()!=10)throw (std::invalid_argument("Argument must have 10 chars"));
    if((value[0] >= 48 && value[0] <= 57)||(value[1] >= 48 && value[1] <= 57)||(value[3] >= 48 && value[3] <= 57)||
       (value[4] >= 48 && value[4] <= 57)||(value[6] >= 48 && value[6] <= 57)||(value[7] >= 48 && value[7] <= 57)||
       (value[8] >= 48 && value[8] <= 57)||(value[9] >= 48 && value[9] <= 57) || value[2]==47 || value[5]==47){}
    else{
        throw (std::invalid_argument("Argument must be DD/MM/AAAA"));
    }
    if(value[3] > '1')throw (std::invalid_argument("MM cant be bigger than 12"));
    if(value[3] == '1'){
        if(value[4] > '2')throw (std::invalid_argument("MM cant be bigger than 12"));
    }
    if((value[3]=='0'&&(value[4]=='1'||value[4]=='3'||value[4]=='5'||value[4]=='7'||
       value[4]=='8'))||((value[3]=='1'&&(value[4]=='0'||value[4]=='2')))){
        if(value[0] > '3')throw (std::invalid_argument("DD cant be bigger than 31"));
        if(value[0] == '3'){
        if(value[1] > '1')throw (std::invalid_argument("MM cant be bigger than 31"));
        }
       }
    if((value[3]=='0'&&(value[4]=='4'||value[4]=='6'||value[4]=='9'))||
        ((value[3]=='1'&&(value[4]=='1')))){
        if(value[0] > '3')throw (std::invalid_argument("DD cant be bigger than 30"));
        if(value[0] == '3'){
        if(value[1] > '0')throw (std::invalid_argument("MM cant be bigger than 30"));
        }
       }

    if(value[6]!=2||value[7]!=0)throw (std::invalid_argument("AAAA has to be 2000 to 2099"));

    if(valor%4==0){
        if(value[3]=='0'&&value[4]=='2'){
           if(value[0] >'2')throw (std::invalid_argument("DD cant be bigger than 28"));
           if(value[0] =='2' && value[1] > '8')throw (std::invalid_argument("DD cant be bigger than 28"));
           }
    }
    else{
        if(value[3]=='0'&&value[4]=='2'){
           if(value[0] >'2')throw (std::invalid_argument("DD cant be bigger than 27"));
           if(value[0] =='2' && value[1] > '7')throw (std::invalid_argument("DD cant be bigger than 27"));
           }
    }
}




