#include <stdexcept>
using namespace std;

// Interfaces do subsistema de autenticaçao

// Interfaces
// Interface da camada de aplicação
class IAuthView;
// Interface da camada de serviço
class IAuthServ;

class IAuthView{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Mostra tela de login e realiza login
    virtual void login()=0;

    // Metodo virtual destrutor
    virtual ~IAuthView();
};

class IAuthServ{
// Métodos abstratos puros que serão sorbeescritos pelas classes controladoras
public:
    // Realiza a autenticação de um usuario
    virtual void authenticate() throw (runtime_error)=0;
};
