#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
    
    srand(time(0));
    
    int anio, mes, boleto, suma=0;
    bool ganar=false;
    
    do {
        cout << "Ingrese anio (>1990): ";
        cin >> anio;
    } while (anio<=1990);
    
    mes=rand()%12+1;
    cout << mes << endl;
    boleto=anio*100+mes;
    
    for (int i=7; i>=2; i--) {
        suma=suma+(boleto%10)*i;
        boleto=boleto/10;
    }
    
    for (int j=2; j<=7; j++) {
        if (suma%11==j) {
            cout << "El premio es: " << 1000*j;
            ganar=true;
        }
    }
    
    if (ganar==false) {
        cout << "No ha ganado el premio";
    }
}