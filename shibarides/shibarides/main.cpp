#include <iostream>
#include "ShibaRidesDomains.hpp"
#include "ShibaRidesDomainsUT.hpp"

using namespace std;
using namespace shibarides;

int main(){
    TUAssento tuassento;

    int r = tuassento.run();
    cout << r << endl;
    switch(r){
    case TUDominio::SUCCESS:
        cout << "SUCCESS" << endl;
        break;
    case TUDominio::FAIL:
        cout << "FAIL" << endl;
        break;
    default:
        cout << "?" << endl;
    }

    return 0;
}
