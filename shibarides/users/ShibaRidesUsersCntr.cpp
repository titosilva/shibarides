#include "ShibaRidesUsersInterfaces.hpp"
#include "ShibaRidesUsersCntr.hpp"
#include "ShibaRidesUsersUI.hpp"

// Implementação das funções das controladoras do subsistema Rides

// CAMADA DE APRESENTAÇÃO
void CntrUsersView::setServiceController(IUserServ *cntr){
    this->service = cntr;
}

bool CntrUsersView::signin() throw (runtime_error){

    Email emailarg;
    Nome nomealarg;
    Senha senhaarg;
    Telefone telefonearg;
    CPF cpfarg;
    CodDeBanco bancoarg;
    NumDeConta contaarg;
    NumDeAgencia agenciaarg;

    // Permanece em loop, indicando ao usuario se o login esta errado
    // ate que ele acerte o signin ou desista da operação
    while(true){
        // Mostra a tela de sign, obtem os dados
        while(true){
            try{
                // Tenta pegar informações do usuario
                if(!UserSigninUI::show(emailarg, senhaarg,nomealarg, cpfarg, telefonearg, bancoarg, contaarg, agenciaarg)){
                    // Caso a função retorne falso, o usuario desistiu do login
                    return false;
                }

                break;
            }catch(const invalid_argument &e){
                // Caso seja lançada uma excessão, o usuário digitou dados invalidos
                UserErrorUI::show("Dados invalidos!");
            }
        }

        // Passa os dados para a camada inferior e verifica se foi possivel
        // realizar a autenticação
        // Aqui, é lançada uma excessão runtime_error caso nao seja possivel
        // acessar a base de dados
        //if()){
            // Caso seja possível autenticar, retorna true
            // e salva em email o argumento obtido do usuario
            return true;
        //}else{
            UserErrorUI::show("Email ja existe");
        //}
    }
}

// Camada de serviço
bool CntrUsersServ::edit(Email email, Senha senha, Nome nome, Telefone telefone, CPF cpf) throw(runtime_error){
}
