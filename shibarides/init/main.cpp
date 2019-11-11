#include <iostream>
using namespace std;

#include "ShibaRidesInitUI.h"
#include "../auth/ShibaRidesAuth.h"

int main(){
    IAuthView *authview = new CntrAuthView();
    IAuthServ *authserv = new CntrAuthServ();

    authview->setServiceController(authserv);

    return 0;
}
