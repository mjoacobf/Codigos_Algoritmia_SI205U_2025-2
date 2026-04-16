#include<iostream>
using namespace std;

int main() {
	int n = -1;
	int Q = 0;
	int cifrasq = 0;
	
	do {
		cout<<"Ingrese la cantidad de numeros a analizar: (n <= 8): ";cin>>n;
	} while (n<=0 or n>8);
	
	int mayorperfecto = -1;
	int vecesmayor = 0;
	
	for (int i = 1; i<=n;i++) {
		int entrada = 0;
		do {
			cout<<"Ingrese el numero entero positivo "<<i<<" (desde 1 hasta 5 cifras): ";cin>>entrada;
		} while (entrada <= 0 or entrada > 99999);
		
		//Determinando si es perfecto:
		int sumadivisorespropios = 0;
		for (int j = 1; j<entrada;j++) {
			if (entrada%j == 0) {
				sumadivisorespropios+=j;
			}
		}
		
		if (entrada == sumadivisorespropios) {
			//Es perfecto
			if (entrada > mayorperfecto) {
				mayorperfecto = entrada;
				vecesmayor = 1;
			} else if (entrada == mayorperfecto) {
				vecesmayor++;
			}
		} else {
			int cantcifras = 0;
			int t = entrada;
			while (t>0) {
				cantcifras++;
				t/=10;
			}
			
			int u = entrada%10;
			int p;
			
			if (cantcifras == 1) {
				p = 1; //Esto se hace solamente para que el producto sea el mismo numero. No implica necesariamente que la primera cifra sea 1.
			} else {
				t = entrada;
				for (int j = 1; j<cantcifras;j++) {
					t/=10;
				}
				p = t%10;
			}
			
			int productocifras = u*p;
			int cifrasdelproducto;
			if (productocifras >= 0 and productocifras<=9) cifrasdelproducto = 1;
			else cifrasdelproducto = 2; //Maximo es 9x9 = 81, por lo tanto, solo hay opcion de que sea de una cifra (0-9) o dos (10-81).
			
			for (int j = 1; j<=cifrasq;j++) {
				productocifras*=10;
			}
			Q+= productocifras;
			cifrasq+=cifrasdelproducto;
			
		}
	}
	
	cout<<"Mayor perfecto: "<<mayorperfecto<<endl;
	cout<<"Apariciones: "<<vecesmayor<<endl;
	
	cout<<"Q: "<<Q<<endl;
	
	return 0;
}
