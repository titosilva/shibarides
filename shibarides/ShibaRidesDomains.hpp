#ifndef SHIBARIDESDOMAINS_HPP_INCLUDED
#define SHIBARIDESDOMAINS_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace shibarides{

// Base class
class Dominio{
public:
    Dominio();
    void setValue(std::string) throw (std::invalid_argument);
    std::string getValue() const;
private:
    virtual void validate(std::string) throw (std::invalid_argument)=0;
    std::string value;
};

// Domains
class Assento : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Bagagem : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeBanco : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeCarona : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeReserva : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Cidade : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CPF : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Data : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Duracao : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Estado : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Email : public Dominio{
private:
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
