#include "../domains/ShibaRidesDomains.hpp"
#include <stdexcept>
using namespace std;
using namespace shibarides;

class AuthLoginUI{
public:
    // Retorna falso caso o usuario tenha desistido da operação
    // Retorna verdadeiro caso contrario e armazena em email e senha
    // os valores obtidos
    static bool show(Email &email, Senha &senha) throw (invalid_argument);
};

class AuthErrorUI{
public:
    // Mostra mensagem de erro
    static void show(string error);
};
