#include "ShibaRidesAuthInterfaces.h"
#include "ShibaRidesAuthCntr.h"
#include "ShibaRidesAuthUI.h"

// Implementação das funções das controladoras do subsistema Auth

// CAMADA DE APRESENTAÇÃO
void CntrAuthView::setServiceController(IAuthServ *cntr){
    this->service = cntr;
}

bool CntrAuthView::login() throw (runtime_error){
    Email email;
    Senha senha;

    // Permanece em loop, indicando ao usuario se o login esta errado
    // ate que ele acerte o login ou desista da operação
    while(true){
        // Mostra a tela de login, obtem os dados
        while(true){
            try{
                // Tenta pegar informações do usuario
                if(!AuthLoginUI.show(email, senha)){
                    // Caso a função retorne falso, o usuario desistiu do login
                    return false;
                }

                break;
            }catch(const invalid_argument &e){
                // Caso seja lançada uma excessão, o usuário digitou dados invalidos
                AuthErrorUI.show("Dados invalidos!");
            }
        }

        // Passa os dados para a camada inferior e verifica se foi possivel
        // realizar a autenticação

    }
}

// CAMADA DE SERVIÇO
bool CntrAuthServ::authenticate(Email email, Senha senha) throw(runtime_error){
    //Tenta acessar a base de dados

    // Faz a verificação
}
