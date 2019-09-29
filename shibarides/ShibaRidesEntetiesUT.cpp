#include "ShibaRidesEntitiesUT.hpp"
using namespace shibarides;

//Usuario
int TUUsuario::run(){
    this->usuario = new Usuario();
    this->state = TUUsuario::SUCCESS;
    this->successCase();
    this->failCase();
    printf("teste2");
    this->destroyUsuario();
    return this->state;
}

void TUUsuario::successCase(){
    Nome nome;
    nome.setValue("Pedro");

    Telefone telefone;
    telefone.setValue("55-61-912345678");

    Email email;
    email.setValue("crash@shibemail.com");

    CPF cpf;
    cpf.setValue("072.143.901-24");
    try{
        this->usuario->setNome(nome);
        if(this->usuario->getNome().getValue() != nome.getValue()) this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setTelefone(telefone);
        if(this->usuario->getTelefone().getValue() != telefone.getValue()) this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setEmail(email);
        if(this->usuario->getEmail().getValue() != email.getValue()) this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setCPF(cpf);
        if(this->usuario->getCPF().getValue() != cpf.getValue()) this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        this->state = TUUsuario::FAIL;
    }
}

void TUUsuario::failCase(){
    Nome nome;
    nome.setValue("Nome++Invalido");

    Telefone telefone;
    telefone.setValue("993955999");

    Email email;
    email.setValue("unvalidEmail.com");

    CPF cpf;
    cpf.setValue("072");
    printf("teste1");
    try{
        this->usuario->setNome(nome);
        this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        if(this->usuario->getNome().getValue() == nome.getValue()) this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setTelefone(telefone);
        this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        if(this->usuario->getTelefone().getValue() == telefone.getValue()) this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setEmail(email);
        this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        if(this->usuario->getEmail().getValue() == email.getValue()) this->state = TUUsuario::FAIL;
    }

    try{
        this->usuario->setCPF(cpf);
        this->state = TUUsuario::FAIL;
    }catch(std::exception e){
        if(this->usuario->getCPF().getValue() == cpf.getValue()) this->state = TUUsuario::FAIL;
    }
}

void TUUsuario::destroyUsuario(){
    delete this->usuario;
}

//Reserva
int TUReserva::run(){
    this->reserva = new Reserva();
    this->state = TUReserva::SUCCESS;
    this->successCase();
    this->failCase();
    this->destroyReserva();
    return this->state;
}

void TUReserva::successCase(){
    CodDeReserva codigo;
    codigo.setValue("00000");

    Assento assento;
    assento.setValue("D");

    Bagagem bagagem;
    bagagem.setValue("0");

    try{
        this->reserva->setCodigo(codigo);
        if(this->reserva->getCodigo().getValue() != codigo.getValue()) this->state = TUReserva::FAIL;
    }catch(std::exception e){
        this->state = TUReserva::FAIL;
    }

    try{
        this->reserva->setAssento(assento);
        if(this->reserva->getAssento().getValue() != assento.getValue()) this->state = TUReserva::FAIL;
    }catch(std::exception e){
        this->state = TUReserva::FAIL;
    }

    try{
        this->reserva->setBagagem(bagagem);
        if(this->reserva->getBagagem().getValue() != bagagem.getValue()) this->state = TUReserva::FAIL;
    }catch(std::exception e){
        this->state = TUReserva::FAIL;
    }

}

void TUReserva::failCase(){
    CodDeReserva codigo;
    codigo.setValue("codInvalido");

    Assento assento;
    assento.setValue("invalido");

    Bagagem bagagem;
    bagagem.setValue("invalido");
    try{
        this->reserva->setCodigo(codigo);
        this->state = TUReserva::FAIL;
    }catch(std::exception e){
        if(this->reserva->getCodigo().getValue() == codigo.getValue()) this->state = TUReserva::FAIL;
    }

    try{
        this->reserva->setAssento(assento);
        this->state = TUReserva::FAIL;
    }catch(std::exception e){
        if(this->reserva->getAssento().getValue() == assento.getValue()) this->state = TUReserva::FAIL;
    }

    try{
        this->reserva->setBagagem(bagagem);
        this->state = TUReserva::FAIL;
    }catch(std::exception e){
        if(this->reserva->getBagagem().getValue() == bagagem.getValue()) this->state = TUReserva::FAIL;
    }
}

void TUReserva::destroyReserva(){
    delete this->reserva;
}

//Carona
int TUCarona::run(){
    this->carona = new Carona();
    this->state = TUCarona::SUCCESS;
    this->successCase();
    this->failCase();
    this->destroyCarona();
    return this->state;
}

void TUCarona::successCase(){
    CodDeCarona codigo;
    codigo.setValue("0000");

    Cidade cidorigem;
    cidorigem.setValue("Df");

    Estado estorigem;
    estorigem.setValue("DF");

    Cidade ciddestino;
    ciddestino.setValue("P.O.");

    Estado estdestino;
    estdestino.setValue("MG");

    Data data;
    data.setValue("03/03/2019");

    Duracao duracao;
    duracao.setValue("06");

    Vagas vagas;
    vagas.setValue("1");

    Preco preco;
    preco.setValue("90.00");

    try{
        this->carona->setCodigo(codigo);
        if(this->carona->getCodigo().getValue() != codigo.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setCidadeOrigem(cidorigem);
        if(this->carona->getCidadeOrigem().getValue() != cidorigem.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setEstadoOrigem(estorigem);
        if(this->carona->getEstadoOrigem().getValue() != estorigem.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setCidadeDestino(ciddestino);
        if(this->carona->getCidadeDestino().getValue() != ciddestino.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setEstadoDestino(estdestino);
        if(this->carona->getEstadoDestino().getValue() != estdestino.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setData(data);
        if(this->carona->getData().getValue() != data.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setDuracao(duracao);
        if(this->carona->getDuracao().getValue() != duracao.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setVagas(vagas);
        if(this->carona->getVagas().getValue() != vagas.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setPreco(preco);
        if(this->carona->getPreco().getValue() != preco.getValue()) this->state = TUCarona::FAIL;
    }catch(std::exception e){
        this->state = TUCarona::FAIL;
    }

}

void TUCarona::failCase(){
    CodDeCarona codigo;
    codigo.setValue("invalidcod");

    Cidade cidorigem;
    cidorigem.setValue("Invalid  City");

    Estado estorigem;
    estorigem.setValue("InvalidEstate");

    Cidade ciddestino;
    ciddestino.setValue("Invalid  City");

    Estado estdestino;
    estdestino.setValue("InvalidEstate");

    Data data;
    data.setValue("03/03/3000");

    Duracao duracao;
    duracao.setValue("invalidDuracao");

    Vagas vagas;
    vagas.setValue("100");

    Preco preco;
    preco.setValue("1000000");
    try{
        this->carona->setCodigo(codigo);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getCodigo().getValue() == codigo.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setCidadeOrigem(cidorigem);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getCidadeOrigem().getValue() == cidorigem.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setCidadeDestino(ciddestino);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getCidadeDestino().getValue() == ciddestino.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setEstadoOrigem(estorigem);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getEstadoOrigem().getValue() == estorigem.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setEstadoDestino(estdestino);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getEstadoDestino().getValue() == estdestino.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setData(data);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getData().getValue() == data.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setDuracao(duracao);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getDuracao().getValue() == duracao.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setVagas(vagas);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getVagas().getValue() == vagas.getValue()) this->state = TUCarona::FAIL;
    }

    try{
        this->carona->setPreco(preco);
        this->state = TUCarona::FAIL;
    }catch(std::exception e){
        if(this->carona->getPreco().getValue() == preco.getValue()) this->state = TUCarona::FAIL;
    }

}

void TUCarona::destroyCarona(){
    delete this->carona;
}

//Conta
int TUConta::run(){
    this->conta = new Conta();
    this->state = TUConta::SUCCESS;
    this->successCase();
    this->failCase();
    this->destroyConta();
    return this->state;
}

void TUConta::successCase(){
    CodDeBanco banco;
    banco.setValue("123");

    NumDeAgencia agencia;
    agencia.setValue("5643-2");

    NumDeConta conta;
    conta.setValue("123456-6");

    try{
        this->conta->setBanco(banco);
        if(this->conta->getBanco().getValue() != banco.getValue()) this->state = TUConta::FAIL;
    }catch(std::exception e){
        this->state = TUConta::FAIL;
    }

    try{
        this->conta->setAgencia(agencia);
        if(this->conta->getAgencia().getValue() != agencia.getValue()) this->state = TUConta::FAIL;
    }catch(std::exception e){
        this->state = TUConta::FAIL;
    }

    try{
        this->conta->setConta(conta);
        if(this->conta->getConta().getValue() != conta.getValue()) this->state = TUConta::FAIL;
    }catch(std::exception e){
        this->state = TUConta::FAIL;
    }

}

void TUConta::failCase(){
    CodDeBanco banco;
    banco.setValue("123");

    NumDeAgencia agencia;
    agencia.setValue("5643-2");

    NumDeConta conta;
    conta.setValue("123456-6");

    try{
        this->conta->setBanco(banco);
        this->state = TUConta::FAIL;
    }catch(std::exception e){
        if(this->conta->getBanco().getValue() == banco.getValue()) this->state = TUConta::FAIL;
    }

    try{
        this->conta->setAgencia(agencia);
        this->state = TUConta::FAIL;
    }catch(std::exception e){
        if(this->conta->getAgencia().getValue() == agencia.getValue()) this->state = TUConta::FAIL;
    }

    try{
        this->conta->setConta(conta);
        this->state = TUConta::FAIL;
    }catch(std::exception e){
        if(this->conta->getConta().getValue() == conta.getValue()) this->state = TUConta::FAIL;
    }
}

void TUConta::destroyConta(){
    delete this->conta;
}


