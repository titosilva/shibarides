#include "ShibaRidesAuthInterfaces.h"
#include "ShibaRidesAuthCntr.h"

// Implementação das funções das controladoras do subsistema Auth

// CAMADA DE APRESENTAÇÃO
void CntrAuthView::setServiceController(IAuthView *cntr){
    this->service = cntr;
}

bool CntrAuthView::login() throw (runtime_error){
    // Mostra a tela de login, obtem os dados

    // Passa os dados para a camada inferior e verifica se foi possivel
    // realizar a autenticação
}

// CAMADA DE SERVIÇO
bool CntrAuthServ::authenticate(Email email, Senha senha) throw(runtime_error){
    //Tenta acessar a base de dados

    // Faz a verificação
}
