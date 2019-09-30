#ifndef SHIBARIDESDOMAINS_HPP_INCLUDED
#define SHIBARIDESDOMAINS_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace shibarides{

// Base class
/** @brief Classe abstrata que serve de base para os domínios

  @details Classe da qual todos os dominios são herdados. Implementa as funçoes setValue e getValue, que servem
           para definir o valor armazenado em um dominio ou retornar esse valor. Todos os valores para os
           dominios sao armazenados na string value.
           É exigida a implementação da função abstrata pura validate em todos os dominios. Essa função
           define as regras pelas quais valores serao aceitos ou recusados pelo dominio.
*/
class Dominio{
public:
    /// @brief Construtor da classe Dominio
    /// @details Apenas define o campo value como string vazia ("")
    Dominio();
    /** @brief Armazena o valor passado, caso este seja valido para o dominio em questão.

        @details A funçao setValue invoca o metodo validate do dominio, com o intuito de verificar
                 se o valor passado é valido. Em caso positivo, o valor é armazenado no campo value do objeto.
                 Em caso negativo, é lançada uma excessão do tipo std::invalid_argument.

        @param value Valor a ser armazenado
    */
    void setValue(std::string) throw (std::invalid_argument);

    /** @brief Retorna o valor armazenado no campo value.

        @details A funçao getValue retorna o valor armazenado pelo dominio. Se o valor ainda nao tiver sido modificado,
                 é retornada uma string vazia.

        @return string Valor armazenado pelo dominio
    */
    std::string getValue() const;
private:
    /** @brief Função privada que define as regras de validação para o dominio.

        @details Função pura abstrata, que é sobrescrita nos domínios e define o comportamento de cada
                 domínio. Caso o valor passado nao seja valido, é lançada uma excessão std::invalid_argument.

        @param string Valor a ser validado.
    */
    virtual void validate(std::string) throw (std::invalid_argument)=0;
    /// @brief Armazena valores (todos os valores sao strings)
    std::string value;
};

// Domains
/** @brief Dominio responsável pela preferência de assento do passageiro.

  @details Representa a preferência de assento do passegeiro.
           Há, somente, duas possibilidades de bancos a serem selecionados: traseiros ou dianteiros. Assentos
           traseiros são denotados com "T", enquanto assentos dianteiros são denotados com "D".
*/
class Assento : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Para o domínio Assento, são aceitos os valores a seguir:

                 <table>
                    <tr>
                        <th>Valor</th>
                        <th>Semântica</th>
                    </tr>
                    <tr>
                        <td>D</td>
                        <td>Assento dianteiro</td>
                    </tr>
                    <tr>
                        <td>T</td>
                        <td>Assento traseiro</td>
                    </tr>
                </table>

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelo numero de volumes da bagagem do passageiro.

  @details Representa a quantidade de volumes na bagagem do passegeiro.
           O numero de volumes da bagagem pode ser qualquer valor de 0 a 4,
           que devem ser passados com string para o método setValue
*/
class Bagagem : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Para o domínio Bagagem, são aceitos os valores "0", "1", "2", "3" ou "4".

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelo código de banco, fornecido pelo usuaŕio.

  @details Representa o código de banco do usuario.
           Os valores aceitos são da forma XXX, onde X é dígito de 0 a 9.
*/
class CodDeBanco : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores aceitos para este dominio
                 são da forma XXX, onde X é dígito de 0 a 9.

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelo código da carona fornecida pelo usuaŕio.

  @details Representa o código de carona fornecida pelo usuario.
           Os valores aceitos são da forma XXXX, onde X é dígito de 0 a 9.
*/
class CodDeCarona : public Dominio{
private:
     /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores aceitos para este dominio
                 são da forma XXXX, onde X é dígito de 0 a 9.

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelo código de reserva, fornecido pelo sistema.

  @details Representa o código de reserva feita pelo usuario.
           Os valores aceitos são da forma XXXXX, onde X é dígito de 0 a 9.
*/
class CodDeReserva : public Dominio{
private:
     /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores aceitos para este dominio
                 são da forma XXXXX, onde X é dígito de 0 a 9.

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelas cidades de origem e destino das caronas.

  @details Representa as cidades selecionadas pelos usuarios.
           Os valores aceitos possuem de 1 a 10 caracteres, que podem ser letra, ponto ou espaço.
           Pelo menos um caracter deve ser letra, antes de ponto deve haver letra e não podem existir
           dois espaços em seguida.
*/
class Cidade : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores aceitos para este dominio possuem de 1 a 10 caracteres,
                 que podem ser letra, ponto ou espaço.
                 Pelo menos um caracter deve ser letra, antes de ponto deve haver letra e não podem existir
                 dois espaços em seguida.

        @param value Valor a ser validado
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pela validação do CPF.

  @details Representa o CPF do usuario.
           Os valores são validados por meio do algoritmo de validação para o CPF.
  @see Explicação do algoritmo https://www.geradorcpf.com/algoritmo_do_cpf.htm
*/
class CPF : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores são validados por meio do algoritmo de CPF, que pode ser encontrado em
                 [link](https://www.geradorcpf.com/algoritmo_do_cpf.htm)

        @param value Valor a ser validado
        @throw std::invalid_argument Argumento invalido pelas regras do dominio
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelas datas.

  @details Representa as datas.
           Os valores permitidos seguem as seguintes regras:

                 Formato DD/MM/AAAA. DD é número de 1 e 31. MM é número de 1 e 12.
                 AAAA é número de 2000 a 2099. A data deve considerar a ocorrência de
                 anos bissextos.
*/
class Data : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores permitidos seguem as seguintes regras:

                 Formato DD/MM/AAAA. DD é número de 1 e 31. MM é número de 1 e 12.
                 AAAA é número de 2000 a 2099. A data deve considerar a ocorrência de
                 anos bissextos.

        @param value Valor a ser validado
        @throw std::invalid_argument Argumento invalido pelas regras do dominio
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pela duração das viagens.

  @details Representa a duração das viagens.
           Os valores permitidos são representados em horas, podendo ser de 1 a 48.
*/
class Duracao : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores permitidos são representados em horas, podendo ser de 1 a 48.

        @param value Valor a ser validado
        @throw std::invalid_argument Argumento invalido pelas regras do dominio
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pelos estados de origem e destino das viagens.

  @details Representa os estados nas caronas.
           Os valores permitidos são representados em siglas para cada estado,
           e podem ser qualquer estado brasileiro.
*/
class Estado : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores permitidos são representados em siglas para cada estado,
                 e podem ser qualquer estado brasileiro:
                 AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE,
                 PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO

        @param value Valor a ser validado
        @throw std::invalid_argument Argumento invalido pelas regras do dominio
    */
    void validate(std::string) throw (std::invalid_argument);
};

/** @brief Dominio responsável pela validação dos endereços de Email.

  @details Representa os emails dos usuarios.

*/
class Email : public Dominio{
private:
    /** @brief Metodo que define as regras de validação para o dominio.

        @details O método validate implementa as regras de validação para o dominio.
                 Os valores permitidos seguem as seguintes regras:

                 Formato local@domínio onde: a parte local pode ter até 20 caracteres; o
                 domíno pode ter até 20 caracteres; cada caracter pode ser letra (a - z) ou ponto
                 (.); a parte local não pode ser iniciada e nem ser terminada por ponto; o
                 domínio não pode ser iniciado por ponto; não podem existir dois pontos em
                 sequência.

        @param value Valor a ser validado
        @throw std::invalid_argument Argumento invalido pelas regras do dominio
    */
    void validate(std::string) throw (std::invalid_argument);
};


class Nome : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class NumDeAgencia : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class NumDeConta : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Preco : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Telefone : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Senha : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Vagas : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

};

#endif // SHIBARIDESDOMAINS_HPP_INCLUDED
