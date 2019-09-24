#ifndef SHIBARIDESDOMAINS_HPP_INCLUDED
#define SHIBARIDESDOMAINS_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace shibarides{

class Dominio{
public:
    Dominio();
    void setValue(std::string) throw (std::invalid_argument);
    std::string getValue() const throw (std::exception);
private:
    virtual void validate(std::string) throw (std::invalid_argument);
    std::string value;
    bool valueSet;
};

class Assento : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

};

#endif // SHIBARIDESDOMAINS_HPP_INCLUDED
