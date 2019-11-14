#include "ShibaRidesUsersInterfaces.hpp"
#include "ShibaRidesUsersCntr.hpp"
#include "ShibaRidesUsersUI.hpp"

// Implementa��o das fun��es das controladoras do subsistema Rides

// CAMADA DE APRESENTA��O
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
    // ate que ele acerte o signin ou desista da opera��o
    while(true){
        // Mostra a tela de sign, obtem os dados
        while(true){
            try{
                // Tenta pegar informa��es do usuario
                if(!UserSigninUI::show(emailarg, senhaarg,nomealarg, cpfarg, telefonearg, bancoarg, contaarg, agenciaarg)){
                    // Caso a fun��o retorne falso, o usuario desistiu do login
                    return false;
                }

                break;
            }catch(const invalid_argument &e){
                // Caso seja lan�ada uma excess�o, o usu�rio digitou dados invalidos
                UserErrorUI::show("Dados invalidos!");
            }
        }

        // Passa os dados para a camada inferior e verifica se foi possivel
        // realizar a autentica��o
        // Aqui, � lan�ada uma excess�o runtime_error caso nao seja possivel
        // acessar a base de dados
        //if()){
            // Caso seja poss�vel autenticar, retorna true
            // e salva em email o argumento obtido do usuario
            return true;
        //}else{
            UserErrorUI::show("Email ja existe");
        //}
    }
}

// Camada de servi�o
bool CntrUsersServ::edit(Email email, Senha senha, Nome nome, Telefone telefone, CPF cpf) throw(runtime_error){
}
