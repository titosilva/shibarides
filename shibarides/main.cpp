#include <iostream>
#include "ShibaRidesDomains.hpp"
#include "ShibaRidesDomainsUT.hpp"
#include "ShibaRidesEntities.hpp"
#include "ShibaRidesEntitiesUT.hpp"

using namespace std;
using namespace shibarides;

template<class TUBase, class TU>
void runTest(string label){
    TU tu;

    cout << "Testing: " << label << endl;
    cout << "> Result: ";

    int r = tu.run();

    switch(r){
    case TUBase::SUCCESS:
        cout << "\033[92m" << "SUCCESS" << "\033[0m" << endl;
        break;
    case TUBase::FAIL:
        cout << "\033[91m" << "FAIL" << "\033[0m" << endl;
        break;
    }

}

int main(){
    cout<< "\033[94m" << "===== DOMAINS =====" << "\033[0m" << endl;

    runTest<TUDominio,TUAssento>("Assento");
    runTest<TUDominio,TUBagagem>("Bagagem");
    runTest<TUDominio,TUCodDeBanco>("CodDeBanco");
    runTest<TUDominio,TUCodDeCarona>("CodDeCarona");
    runTest<TUDominio,TUCodDeReserva>("CodDeReserva");
    runTest<TUDominio,TUCidade>("Cidade");
    runTest<TUDominio,TUCPF>("CPF");
    runTest<TUDominio,TUData>("Data");
    runTest<TUDominio,TUDuracao>("Duracao");
    runTest<TUDominio,TUEstado>("Estado");
    runTest<TUDominio,TUEmail>("Email");
    runTest<TUDominio,TUNome>("Nome");
    runTest<TUDominio,TUNumDeAgencia>("NumDeAgencia");
    runTest<TUDominio,TUNumDeConta>("NumDeConta");
    runTest<TUDominio,TUPreco>("Preco");
    runTest<TUDominio,TUTelefone>("Telefone");
    runTest<TUDominio,TUSenha>("Senha");
    runTest<TUDominio,TUVagas>("Vagas");

    cout<< endl << "\033[94m" << "===== ENTITIES =====" << "\033[0m" << endl;

    runTest<TUEntidade, TUUsuario>("Usuario");


    return 0;
}
