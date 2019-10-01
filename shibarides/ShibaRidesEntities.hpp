#ifndef SHIBARIDESENTITIES_HPP_INCLUDED
#define SHIBARIDESENTITIES_HPP_INCLUDED
#include "ShibaRidesDomains.hpp"


namespace shibarides{

class Usuario{
    //Usuario
    /** @brief Classe que representa a entidade de usuario.
    details Classe que armazena os dominios de Nome, Telefone, email, senha e CPF de cada Usuario.
    */
public:
    // Nome methods
    void setNome(const Nome &nome){
        this->nome = nome;
    }
    /** @brief Armazena um valor de Nome.

        @details Ela armazena o valor passado de Nome no dominio caso esteja dentro dos padroes do dominio.

        @param nome Objeto do tipo Nome a ser armazenado.
    */
    Nome getNome() const{
        return this->nome;
    }
    /** @brief Retorna o valor de Nome previamente armazenado.

        @details Ela retorna o valor armazenado de Nome no dominio.

        @return nome Objeto do tipo Nome a ser armazenado.
    */

    // Telefone methods
    void setTelefone(const Telefone &telefone){
        this->telefone = telefone;
    }
    /** @brief Armazena um valor de Telefone.

        @details Ela armazena o valor passado de Telefone no dominio caso esteja dentro dos padroes do dominio.

        @param telefone Objeto do tipo Telelfone que esta armazenado.
    */
    Telefone getTelefone() const{
        return this->telefone;
    }
    /** @brief Retorna o valor de Telefone previamente armazenado.

        @details Ela retorna o valor armazenado de Telefone no dominio.

        @return telefone Objeto do tipo Telefone que esta armazenado.
    */

    // Email methods
    void setEmail(const Email &email){
        this->email = email;
    }
    /** @brief Armazena um valor de Email.

        @details Ela armazena o valor passado de Email no dominio caso esteja dentro dos padroes do dominio.

        @param email Objeto do tipo Email que esta armazenado.
    */
    Email getEmail() const{
        return this->email;
    }
    /** @brief Retorna o valor de Email previamente armazenado.

        @details Ela retorna o valor armazenado de Email no dominio.

        @return email Objeto do tipo Email que esta armazenado.
    */

    // Senha methods
    void setSenha(const Senha &senha){
        this->senha = senha;
    }
    /** @brief Armazena um valor de Senha.

        @details Ela armazena o valor passado de Senha no dominio caso esteja dentro dos padroes do dominio.

        @param senha Objeto do tipo Senha que esta armazenado.
    */
    Senha getSenha() const{
        return this->senha;
    }
    /** @brief Retorna o valor de Senha previamente armazenado.

        @details Ela retorna o valor armazenado de Senha no dominio.

        @return senha Objeto do tipo Senha que esta armazenado.
    */

    // CPF methods
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }
    /** @brief Armazena um valor de CPF.

        @details Ela armazena o valor passado de CPF no dominio caso esteja dentro dos padroes do dominio.

        @param cpf Objeto do tipo CPF que esta armazenado.
    */
    CPF getCPF() const{
        return this->cpf;
    }
    /** @brief Retorna o valor de CPF previamente armazenado.

        @details Ela retorna o valor armazenado de CPF no dominio.

        @return cpf Objeto do tipo CPF que esta armazenado.
    */

private:
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;
};

class Reserva{
    //Reserva
    /** @brief Classe que representa a entidade de Reserva.
        @details Classe que armazena os dominios de Codigo de Reserva, Bagagem e Assento de cada Reserva.
    */
public:
    // Codigo methods
    void setCodigo(const CodDeReserva &codigo){
        this->codigo = codigo;
    }
    /** @brief Armazena um valor de CodDeReserva.

        @details Ela armazena o valor passado de CodDeReserva no dominio caso esteja dentro dos padroes do dominio.

        @param codigo Objeto do tipo CodDeReserva que esta armazenado.
    */
    CodDeReserva getCodigo() const{
        return this->codigo;
    }
    /** @brief Retorna o valor de CodDeReserva previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeReserva no dominio.

        @return codigo Objeto do tipo CodDeReserva que esta armazenado.
    */

    // Assento methods
    void setAssento(const Assento &assento){
        this->assento = assento;
    }
    /** @brief Armazena um valor de Assento.

        @details Ela armazena o valor passado de Assento no dominio caso esteja dentro dos padroes do dominio.

        @param assento Objeto do tipo Assento que esta armazenado.
    */
    Assento getAssento() const{
        return this->assento;
    }
     /** @brief Retorna o valor de Assento previamente armazenado.

        @details Ela retorna o valor armazenado de Assento no dominio.

        @return assento Objeto do tipo Assento que esta armazenado.
    */

    // Bagagem methods
    void setBagagem(const Bagagem &bagagem){
        this->bagagem = bagagem;
    }
    /** @brief Armazena um valor de Bagagem.

        @details Ela armazena o valor passado de Bagagem no dominio caso esteja dentro dos padroes do dominio.

        @param bagagem Objeto do tipo Bagagem que esta armazenado.
    */
    Bagagem getBagagem() const{
        return this->bagagem;
    }
    /** @brief Retorna o valor de Bagagem previamente armazenado.

        @details Ela retorna o valor armazenado de Bagagem no dominio.

        @return bagagem Objeto do tipo Bagagem que esta armazenado.
    */
private:
    CodDeReserva codigo;
    Assento assento;
    Bagagem bagagem;
};

class Carona{
    //Carona
    /** @brief Classe que representa a entidade de Carona.
        @details Classe que armazena os dominios de Codigo de Carona, Cidade de Origem, Estado de Origem, Cidade de Destino,
        Estado de Destino, Data, Duracao, Vagas e Preco de cada Carona.
    */
public:
    // Codigo methods
    void setCodigo(const CodDeCarona &codigo){
        this->codigo = codigo;
    }
    /** @brief Armazena um valor de CodDeCarona.

        @details Ela armazena o valor passado de CodDeCarona no dominio caso esteja dentro dos padroes do dominio.

        @param codigo Objeto do tipo CodDeCarona que esta armazenado.
    */
    CodDeCarona getCodigo() const{
        return this->codigo;
    }
    /** @brief Retorna o valor de CodDeCarona previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeCarona no dominio.

        @return codigo Objeto do tipo CodDeCarona que esta armazenado.
    */

    // CidadeOrigem methods
    void setCidadeOrigem(const Cidade &cidorigem){
        this->cidorigem = cidorigem;
    }
    /** @brief Armazena um valor de CidadeOrigem.

        @details Ela armazena o valor passado de CidadeOrigem no dominio caso esteja dentro dos padroes do dominio.

        @param cidorigem Objeto do tipo Cidade que esta armazenado.
    */
    Cidade getCidadeOrigem() const{
        return this->cidorigem;
    }
    /** @brief Retorna o valor de CidadeOrigem previamente armazenado.

        @details Ela retorna o valor armazenado de CidadeOrigem no dominio.

        @return cidorigem Objeto do tipo CidadeOrigem que esta armazenado.
    */

    // EstadoOrigem methods
    void setEstadoOrigem(const Estado &estorigem){
        this->estorigem = estorigem;
    }
    /** @brief Armazena um valor de EstadoOrigem.

        @details Ela armazena o valor passado de EstadoOrigem no dominio caso esteja dentro dos padroes do dominio.

        @param estorigem Objeto do tipo Estado que esta armazenado.
    */
    Estado getEstadoOrigem() const{
        return this->estorigem;
    }
    /** @brief Retorna o valor de EstadoOrigem previamente armazenado.

        @details Ela retorna o valor armazenado de EstadoOrigem no dominio.

        @return estorigem Objeto do tipo Estado que esta armazenado.
    */

    // CidadeDestino methods
    void setCidadeDestino(const Cidade &ciddestino){
        this->ciddestino = ciddestino;
    }
    /** @brief Armazena um valor de CidadeDestino.

        @details Ela armazena o valor passado de CidadeDestino no dominio caso esteja dentro dos padroes do dominio.

        @param ciddestino Objeto do tipo Cidade que esta armazenado.
    */
    Cidade getCidadeDestino() const{
        return this->ciddestino;
    }
    /** @brief Retorna o valor de CidadeDestino previamente armazenado.

        @details Ela retorna o valor armazenado de CidadeDestino no dominio.

        @return ciddestino Objeto do tipo Cidade que esta armazenado.
    */

    // EstadoDestino methods
    void setEstadoDestino(const Estado &estdestino){
        this->estdestino = estdestino;
    }
    /** @brief Armazena um valor de EstadoDestino.

        @details Ela armazena o valor passado de EstadoDestino no dominio caso esteja dentro dos padroes do dominio.

        @param estdestino Objeto do tipo Estado que esta armazenado.
    */
    Estado getEstadoDestino() const{
        return this->estdestino;
    }
    /** @brief Retorna o valor de EstadoDestino previamente armazenado.

        @details Ela retorna o valor armazenado de EstadoDestino no dominio.

        @return estdestino Objeto do tipo Estado que esta armazenado.
    */

    // Data methods
    void setData(const Data &data){
        this->data = data;
    }
    /** @brief Armazena um valor de Data.

        @details Ela armazena o valor passado de Data no dominio caso esteja dentro dos padroes do dominio.

        @param data Objeto do tipo Data que esta armazenado.
    */
    Data getData() const{
        return this->data;
    }
    /** @brief Retorna o valor de Data previamente armazenado.

        @details Ela retorna o valor armazenado de Data no dominio.

        @return data Objeto do tipo Data que esta armazenado.
    */

    // Duracao methods
    void setDuracao(const Duracao &duracao){
        this->duracao = duracao;
    }
    /** @brief Armazena um valor de Duracao.

        @details Ela armazena o valor passado de Duracao no dominio caso esteja dentro dos padroes do dominio.

        @param duracao Objeto do tipo Duracao que esta armazenado.
    */
    Duracao getDuracao() const{
        return this->duracao;
    }
    /** @brief Retorna o valor de Duracao previamente armazenado.

        @details Ela retorna o valor armazenado de Duracao no dominio.

        @return duracao Objeto do tipo Duracao que esta armazenado.
    */

    // Vagas methods
    void setVagas(const Vagas &vagas){
        this->vagas = vagas;
    }
    /** @brief Armazena um valor de Vagas.

        @details Ela armazena o valor passado de Vagas no dominio caso esteja dentro dos padroes do dominio.

        @param vagas Objeto do tipo Vagas que esta armazenado.
    */
    Vagas getVagas() const{
        return this->vagas;
    }
    /** @brief Retorna o valor de Vagas previamente armazenado.

        @details Ela retorna o valor armazenado de Vagas no dominio.

        @return vagas Objeto do tipo Vagas que esta armazenado.
    */

    // Preco methods
    void setPreco(const Preco &preco){
        this->preco = preco;
    }
    /** @brief Armazena um valor de Preco.

        @details Ela armazena o valor passado de Preco no dominio caso esteja dentro dos padroes do dominio.

        @param preco Objeto do tipo Preco que esta armazenado.
    */
    Preco getPreco() const{
        return this->preco;
    }
    /** @brief Retorna o valor de Preco previamente armazenado.

        @details Ela retorna o valor armazenado de Preco no dominio.

        @return preco Objeto do tipo Preco que esta armazenado.
    */
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

class Conta{
    //Conta
    /** @brief Classe que representa a entidade de Conta.
        @details Classe que armazena os dominios de Codigo do Banco, Numero da Agencia e numero da conta de cada Conta.
    */
public:
    // Banco methods
    void setBanco(const CodDeBanco &banco){
        this->banco = banco;
    }
    /** @brief Armazena um valor de CodDeBanco.

        @details Ela armazena o valor passado de CodDeBanco no dominio caso esteja dentro dos padroes do dominio.

        @param banco Objeto do tipo CodDeBanco que esta armazenado.
    */
    CodDeBanco getBanco() const{
        return this->banco;
    }
    /** @brief Retorna o valor de CodDeBanco previamente armazenado.

        @details Ela retorna o valor armazenado de CodDeBanco no dominio.

        @return banco Objeto do tipo CodDeBanco que esta armazenado.
    */

    // Agencia methods
    void setAgencia(const NumDeAgencia &agencia){
        this->agencia = agencia;
    }
    /** @brief Armazena um valor de NumDeAgencia.

        @details Ela armazena o valor passado de NumDeAgencia no dominio caso esteja dentro dos padroes do dominio.

        @param agencia Objeto do tipo NumDeAgencia que esta armazenado.
    */
    NumDeAgencia getAgencia() const{
        return this->agencia;
    }
    /** @brief Retorna o valor de NumDeAgencia previamente armazenado.

        @details Ela retorna o valor armazenado de NumDeAgencia no dominio.

        @return agencia Objeto do tipo NumDeAgencia que esta armazenado.
    */

    // Conta methods
    void setConta(const NumDeConta &conta){
        this->conta = conta;
    }
    /** @brief Armazena um valor de NumDeConta.

        @details Ela armazena o valor passado de NumDeConta no dominio caso esteja dentro dos padroes do dominio.

        @param conta Objeto do tipo NumDeConta que esta armazenado.
    */
    NumDeConta getConta() const{
        return this->conta;
    }
    /** @brief Retorna o valor de NumDeConta previamente armazenado.

        @details Ela retorna o valor armazenado de NumDeConta no dominio.

        @return conta Objeto do tipo NumDeConta que esta armazenado.
    */
private:
    CodDeBanco banco;
    NumDeAgencia agencia;
    NumDeConta conta;
};

}

#endif // SHIBARIDESENTITIES_HPP_INCLUDED
