#include "ShibaRidesAuthInterfaces.h"
#include "ShibaRidesAuthCntr.h"
#include "ShibaRidesAuthUI.h"

// Implementação das funções das controladoras do subsistema Auth

// CAMADA DE APRESENTAÇÃO
void CntrAuthView::setServiceController(IAuthServ *cntr){
    this->service = cntr;
}

bool CntrAuthView::login(Email &email) throw (runtime_error){
    Email emailarg;
    Senha senhaarg;

    // Permanece em loop, indicando ao usuario se o login esta errado
    // ate que ele acerte o login ou desista da operação
    while(true){
        // Mostra a tela de login, obtem os dados
        bool loop = true;
        while(loop){
            try{
                // Tenta pegar informações do usuario
                if(!AuthLoginUI::show(emailarg, senhaarg)){
                    // Caso a função retorne falso, o usuario desistiu do login
                    return false;
                }

                loop = false;
            }catch(const invalid_argument &e){
                // Caso seja lançada uma excessão, o usuário digitou dados invalidos
                AuthErrorUI::show("Dados invalidos!");
            }
        }

        // Passa os dados para a camada inferior e verifica se foi possivel
        // realizar a autenticação
        // Aqui, é lançada uma excessão runtime_error caso nao seja possivel
        // acessar a base de dados
        if(this->service->authenticate(emailarg, senhaarg)){
            // Caso seja possível autenticar, retorna true
            // e salva em email o argumento obtido do usuario
            email = emailarg;
            AuthInfoUI::show("Successfully Logged");
            return true;
        }else{
            AuthErrorUI::show("Email ou senha incorretos!");
        }
    }
}

// CAMADA DE SERVIÇO
bool CntrAuthServ::authenticate(Email email, Senha senha) throw(runtime_error){
    //Tenta acessar a base de dados

    // Faz a verificação
}
