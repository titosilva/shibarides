#include <iostream>
#include "ShibaRidesDomains.hpp"
#include "ShibaRidesDomainsUT.hpp"
#include "ShibaRidesEntities.hpp"
#include "ShibaRidesEntitiesUT.hpp"

using namespace std;
using namespace shibarides;

template<class TU>
void runTest(string label){
    TU tu;

    cout << "Testing: " << label << endl;
    cout << "> Result: ";

    int r = tu.run();

    switch(r){
    case TUDominio::SUCCESS:
        cout << "SUCCESS" << endl;
        break;
    case TUDominio::FAIL:
        cout << "FAIL" << endl;
        break;
    default:
        cout << "UNDEFINED" << endl;
    }

}

void runTestUsuario(string label){
    TUUsuario tu;
    cout << "Testing: "<< label << endl;
    cout << "> Result: ";

    int r = tu.run();
    printf("testte");
    switch(r){
    case TUUsuario::SUCCESS:
        cout << "SUCCESS" << endl;
        break;
    case TUUsuario::FAIL:
        cout << "FAIL" << endl;
        break;
    default:
        cout << "UNDEFINED" << endl;
    }

}

int main(){
    runTest<TUAssento>("Assento");
    runTest<TUBagagem>("Bagagem");
    runTest<TUCodDeBanco>("CodDeBanco");
    runTest<TUCodDeCarona>("CodDeCarona");
    runTest<TUCodDeReserva>("CodDeReserva");
    runTest<TUCidade>("Cidade");
    runTest<TUCPF>("CPF");
    runTest<TUData>("Data");
    runTest<TUDuracao>("Duracao");
    runTest<TUEstado>("Estado");
    runTest<TUEmail>("Email");
    runTest<TUNome>("Nome");
    runTest<TUNumDeAgencia>("NumDeAgencia");
    runTest<TUNumDeConta>("NumDeConta");
    runTest<TUPreco>("Preco");
    runTest<TUTelefone>("Telefone");
    runTest<TUSenha>("Senha");
    runTest<TUVagas>("Vagas");
    runTestUsuario("Usuario");


    return 0;
}
