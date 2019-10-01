#ifndef SHIBARIDESENTITIES_HPP_INCLUDED
#define SHIBARIDESENTITIES_HPP_INCLUDED
#include "ShibaRidesDomains.hpp"


namespace shibarides{
    /** @brief Classe que representa a entidade de usuario.
    details Classe que armazena os dominios de Nome, Telefone, email, senha e CPF de cada Usuario.
    */
class Usuario{
    //Usuario

public:
    // Nome methods
    /** @brief Armazena um valor de Nome.

        @details Ela armazena o valor passado de Nome no dominio caso esteja dentro dos padroes do dominio.

        @param nome Objeto do tipo Nome a ser armazenado.
    */
    void setNome(const Nome &nome){
        this->nome = nome;
    }
    /** @brief Retorna o valor de Nome previamente armazenado.

        @details Ela retorna o valor armazenado de Nome no dominio.

        @return nome Objeto do tipo Nome a ser armazenado.
    */
    Nome getNome() const{
        return this->nome;
    }


    // Telefone methods
    /** @brief Armazena um valor de Telefone.

        @details Ela armazena o valor passado de Telefone no dominio caso esteja dentro dos padroes do dominio.

        @param telefone Objeto do tipo Telelfone que esta armazenado.
    */
    void setTelefone(const Telefone &telefone){
        this->telefone = telefone;
    }

    /** @brief Retorna o valor de Telefone previamente armazenado.

        @details Ela retorna o valor armazenado de Telefone no dominio.

        @return telefone Objeto do tipo Telefone que esta armazenado.
    */
    Telefone getTelefone() const{
        return this->telefone;
    }


    // Email methods
    /** @brief Armazena um valor de Email.

        @details Ela armazena o valor passado de Email no dominio caso esteja dentro dos padroes do dominio.

        @param email Objeto do tipo Email que esta armazenado.
    */
    void setEmail(const Email &email){
        this->email = email;
    }

    /** @brief Retorna o valor de Email previamente armazenado.

        @details Ela retorna o valor armazenado de Email no dominio.

        @return email Objeto do tipo Email que esta armazenado.
    */
    Email getEmail() const{
        return this->email;
    }


    // Senha methods
    /** @brief Armazena um valor de Senha.

        @details Ela armazena o valor passado de Senha no dominio caso esteja dentro dos padroes do dominio.

        @param senha Objeto do tipo Senha que esta armazenado.
    */
    void setSenha(const Senha &senha){
        this->senha = senha;
    }

    /** @brief Retorna o valor de Senha previamente armazenado.

        @details Ela retorna o valor armazenado de Senha no dominio.

        @return senha Objeto do tipo Senha que esta armazenado.
    */
    Senha getSenha() const{
        return this->senha;
    }


    // CPF methods
    /** @brief Armazena um valor de CPF.

        @details Ela armazena o valor passado de CPF no dominio caso esteja dentro dos padroes do dominio.

        @param cpf Objeto do tipo CPF que esta armazenado.
    */
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }

    /** @brief Retorna o valor de CPF previamente armazenado.

        @details Ela retorna o valor armazenado de CPF no dominio.

        @return cpf Objeto do tipo CPF que esta armazenado.
    */
    CPF getCPF() const{
        return this->cpf;
    }


private:
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;
};
    /** @brief Classe que representa a entidade de Reserva.
        @details Classe que armazena os dominios de Codigo de Reserva, Bagagem e Assento de cada Reserva.
    */
class Reserva{
    //Reserva

public:
    // Codigo methods
    /** @brief Armazena um valor de CodDeReserva.

        @details Ela armazena o valor passado de CodDeReserva no dominio caso esteja dentro dos padroes do dominio.

        @param codigo Objeto do tipo CodDeReserva que esta armazenado.
    */
    void setCodigo(const CodDeReserva &codigo){
        this->codigo = codigo;
    }

    /** @brief Retorna o valor de CodDeReserva previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeReserva no dominio.

        @return codigo Objeto do tipo CodDeReserva que esta armazenado.
    */
    CodDeReserva getCodigo() const{
        return this->codigo;
    }


    // Assento methods
    /** @brief Armazena um valor de Assento.

        @details Ela armazena o valor passado de Assento no dominio caso esteja dentro dos padroes do dominio.

        @param assento Objeto do tipo Assento que esta armazenado.
    */
    void setAssento(const Assento &assento){
        this->assento = assento;
    }

    /** @brief Retorna o valor de Assento previamente armazenado.

        @details Ela retorna o valor armazenado de Assento no dominio.

        @return assento Objeto do tipo Assento que esta armazenado.
    */
    Assento getAssento() const{
        return this->assento;
    }


    // Bagagem methods
    /** @brief Armazena um valor de Bagagem.

        @details Ela armazena o valor passado de Bagagem no dominio caso esteja dentro dos padroes do dominio.

        @param bagagem Objeto do tipo Bagagem que esta armazenado.
    */
    void setBagagem(const Bagagem &bagagem){
        this->bagagem = bagagem;
    }

    /** @brief Retorna o valor de Bagagem previamente armazenado.

        @details Ela retorna o valor armazenado de Bagagem no dominio.

        @return bagagem Objeto do tipo Bagagem que esta armazenado.
    */
    Bagagem getBagagem() const{
        return this->bagagem;
    }

private:
    CodDeReserva codigo;
    Assento assento;
    Bagagem bagagem;
};
    /** @brief Classe que representa a entidade de Carona.
        @details Classe que armazena os dominios de Codigo de Carona, Cidade de Origem, Estado de Origem, Cidade de Destino,
        Estado de Destino, Data, Duracao, Vagas e Preco de cada Carona.
    */
class Carona{
    //Carona

public:
    // Codigo methods
    /** @brief Armazena um valor de CodDeCarona.

        @details Ela armazena o valor passado de CodDeCarona no dominio caso esteja dentro dos padroes do dominio.

        @param codigo Objeto do tipo CodDeCarona que esta armazenado.
    */
    void setCodigo(const CodDeCarona &codigo){
        this->codigo = codigo;
    }

    /** @brief Retorna o valor de CodDeCarona previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeCarona no dominio.

        @return codigo Objeto do tipo CodDeCarona que esta armazenado.
    */
    CodDeCarona getCodigo() const{
        return this->codigo;
    }


    // CidadeOrigem methods
    /** @brief Armazena um valor de CidadeOrigem.

        @details Ela armazena o valor passado de CidadeOrigem no dominio caso esteja dentro dos padroes do dominio.

        @param cidorigem Objeto do tipo Cidade que esta armazenado.
    */
    void setCidadeOrigem(const Cidade &cidorigem){
        this->cidorigem = cidorigem;
    }

    /** @brief Retorna o valor de CidadeOrigem previamente armazenado.

        @details Ela retorna o valor armazenado de CidadeOrigem no dominio.

        @return cidorigem Objeto do tipo CidadeOrigem que esta armazenado.
    */
    Cidade getCidadeOrigem() const{
        return this->cidorigem;
    }


    // EstadoOrigem methods
    /** @brief Armazena um valor de EstadoOrigem.

        @details Ela armazena o valor passado de EstadoOrigem no dominio caso esteja dentro dos padroes do dominio.

        @param estorigem Objeto do tipo Estado que esta armazenado.
    */
    void setEstadoOrigem(const Estado &estorigem){
        this->estorigem = estorigem;
    }

    /** @brief Retorna o valor de EstadoOrigem previamente armazenado.

        @details Ela retorna o valor armazenado de EstadoOrigem no dominio.

        @return estorigem Objeto do tipo Estado que esta armazenado.
    */
    Estado getEstadoOrigem() const{
        return this->estorigem;
    }


    // CidadeDestino methods
    /** @brief Armazena um valor de CidadeDestino.

        @details Ela armazena o valor passado de CidadeDestino no dominio caso esteja dentro dos padroes do dominio.

        @param ciddestino Objeto do tipo Cidade que esta armazenado.
    */
    void setCidadeDestino(const Cidade &ciddestino){
        this->ciddestino = ciddestino;
    }

    /** @brief Retorna o valor de CidadeDestino previamente armazenado.

        @details Ela retorna o valor armazenado de CidadeDestino no dominio.

        @return ciddestino Objeto do tipo Cidade que esta armazenado.
    */
    Cidade getCidadeDestino() const{
        return this->ciddestino;
    }


    // EstadoDestino methods
    /** @brief Armazena um valor de EstadoDestino.

        @details Ela armazena o valor passado de EstadoDestino no dominio caso esteja dentro dos padroes do dominio.

        @param estdestino Objeto do tipo Estado que esta armazenado.
    */
    void setEstadoDestino(const Estado &estdestino){
        this->estdestino = estdestino;
    }

    /** @brief Retorna o valor de EstadoDestino previamente armazenado.

        @details Ela retorna o valor armazenado de EstadoDestino no dominio.

        @return estdestino Objeto do tipo Estado que esta armazenado.
    */
    Estado getEstadoDestino() const{
        return this->estdestino;
    }


    // Data methods
    /** @brief Armazena um valor de Data.

        @details Ela armazena o valor passado de Data no dominio caso esteja dentro dos padroes do dominio.

        @param data Objeto do tipo Data que esta armazenado.
    */
    void setData(const Data &data){
        this->data = data;
    }

    /** @brief Retorna o valor de Data previamente armazenado.

        @details Ela retorna o valor armazenado de Data no dominio.

        @return data Objeto do tipo Data que esta armazenado.
    */

    Data getData() const{
        return this->data;
    }

    // Duracao methods
    /** @brief Armazena um valor de Duracao.

        @details Ela armazena o valor passado de Duracao no dominio caso esteja dentro dos padroes do dominio.

        @param duracao Objeto do tipo Duracao que esta armazenado.
    */
    void setDuracao(const Duracao &duracao){
        this->duracao = duracao;
    }

    /** @brief Retorna o valor de Duracao previamente armazenado.

        @details Ela retorna o valor armazenado de Duracao no dominio.

        @return duracao Objeto do tipo Duracao que esta armazenado.
    */
    Duracao getDuracao() const{
        return this->duracao;
    }


    // Vagas methods
    /** @brief Armazena um valor de Vagas.

        @details Ela armazena o valor passado de Vagas no dominio caso esteja dentro dos padroes do dominio.

        @param vagas Objeto do tipo Vagas que esta armazenado.
    */
    void setVagas(const Vagas &vagas){
        this->vagas = vagas;
    }

    /** @brief Retorna o valor de Vagas previamente armazenado.

        @details Ela retorna o valor armazenado de Vagas no dominio.

        @return vagas Objeto do tipo Vagas que esta armazenado.
    */
    Vagas getVagas() const{
        return this->vagas;
    }


    // Preco methods
    /** @brief Armazena um valor de Preco.

        @details Ela armazena o valor passado de Preco no dominio caso esteja dentro dos padroes do dominio.

        @param preco Objeto do tipo Preco que esta armazenado.
    */
    void setPreco(const Preco &preco){
        this->preco = preco;
    }

    /** @brief Retorna o valor de Preco previamente armazenado.

        @details Ela retorna o valor armazenado de Preco no dominio.

        @return preco Objeto do tipo Preco que esta armazenado.
    */
    Preco getPreco() const{
        return this->preco;
    }

private:
    CodDeCarona codigo;
    Cidade cidorigem;
    Estado estorigem;
    Cidade ciddestino;
    Estado estdestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;
};
    /** @brief Classe que representa a entidade de Conta.
        @details Classe que armazena os dominios de Codigo do Banco, Numero da Agencia e numero da conta de cada Conta.
    */
class Conta{
    //Conta

public:
    // Banco methods
    /** @brief Armazena um valor de CodDeBanco.

        @details Ela armazena o valor passado de CodDeBanco no dominio caso esteja dentro dos padroes do dominio.

        @param banco Objeto do tipo CodDeBanco que esta armazenado.
    */
    void setBanco(const CodDeBanco &banco){
        this->banco = banco;
    }

    /** @brief Retorna o valor de CodDeBanco previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeBanco no dominio.

        @return banco Objeto do tipo CodDeBanco que esta armazenado.
    */
    CodDeBanco getBanco() const{
        return this->banco;
    }


    // Agencia methods
    /** @brief Armazena um valor de NumDeAgencia.

        @details Ela armazena o valor passado de NumDeAgencia no dominio caso esteja dentro dos padroes do dominio.

        @param agencia Objeto do tipo NumDeAgencia que esta armazenado.
    */
    void setAgencia(const NumDeAgencia &agencia){
        this->agencia = agencia;
    }

    /** @brief Retorna o valor de NumDeAgencia previamente armazenado.

        @details Ela retorna o valor armazenado de NumDeAgencia no dominio.

        @return agencia Objeto do tipo NumDeAgencia que esta armazenado.
    */
    NumDeAgencia getAgencia() const{
        return this->agencia;
    }


    // Conta methods
    /** @brief Armazena um valor de NumDeConta.

        @details Ela armazena o valor passado de NumDeConta no dominio caso esteja dentro dos padroes do dominio.

        @param conta Objeto do tipo NumDeConta que esta armazenado.
    */
    void setConta(const NumDeConta &conta){
        this->conta = conta;
    }

    /** @brief Retorna o valor de NumDeConta previamente armazenado.

        @details Ela retorna o valor armazenado de NumDeConta no dominio.

        @return conta Objeto do tipo NumDeConta que esta armazenado.
    */
    NumDeConta getConta() const{
        return this->conta;
    }

private:
    CodDeBanco banco;
    NumDeAgencia agencia;
    NumDeConta conta;
};

}

#endif // SHIBARIDESENTITIES_HPP_INCLUDED
