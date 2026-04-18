//Para un conjunto de n (n<=100) personas se desea almacenar por cada una de ellas: código (entero de 3 dígitos), peso (real) y talla (real). Luego presente a la peronas o personas con el peso mayor. En caso de empate ordenarlos en forma ascedente por talla. Además, debe indicar la frecuencia del peso mayor.
#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de personas a analizar (maximo 100): ";cin>>n;
	} while (n<=0 or n>100);
	
	int codigo[n] = {0};
	float peso[n] = {0};
	float talla[n] = {0};
	
	int mayores[n] = {-1};
	float mayor;
	int frecuenciamayor = 1; //Para la primera vez
	
	for (int i = 0; i<n; i++) {
		do {
			cout<<"Ingrese el codigo "<<i+1<<" (entero de tres digitos): ";cin>>codigo[i];
		} while (codigo[i] < 100 or codigo[i] > 999);
		
		do {
			cout<<"Ingrese el peso del codigo "<<codigo[i]<<" (en kg): ";cin>>peso[i];
		} while (peso[i] <=0);
		
		if (i == 0) {
			mayor = peso[i];
			mayores[frecuenciamayor-1] = i;
		}
		else {
			if (peso[i] > mayor) {
				mayor = peso[i];
				frecuenciamayor = 1;
				for (int j = 0; j<n; j++) {
					mayores[j] = -1;
				}
				mayores[frecuenciamayor-1] = i;
			} else if (peso[i] == mayor) {
				frecuenciamayor++;
				mayores[frecuenciamayor-1] = i;
				cout<<"xd se pone "<<i<<"en "<<frecuenciamayor-1<<endl;
			}
		}
		
		
		do {
			cout<<"Ingrese la talla del codigo "<<codigo[i]<<" (en m): ";cin>>talla[i];
		} while (talla[i] <=0);
	}
	
	for (int i = 0; i<frecuenciamayor; i++) {
		for (int j = 0; j<frecuenciamayor;j++) {
			
			if (talla[mayores[i]]<talla[mayores[j]]) {
				
				int t = mayores[j];
				mayores[j] = mayores[i];
				mayores[i] = t;
				

			}
	}
	}

	

	cout<<"Codigo\tPeso\tTalla"<<endl;
	for (int i = 0; i<frecuenciamayor;i++) {
		if (mayores[i] == -1) break;
		else {
			cout<<codigo[mayores[i]]<<"\t"<<peso[mayores[i]]<<"\t"<<talla[mayores[i]]<<endl;
		}
	}
	
	cout<<"Frecuencia del peso mayor: "<<frecuenciamayor;
	
	
	
	
	
	
	return 0;
}
/*
6
123
78.4
1.90
456
50.4
1.60
567
60.2
1.70
789
78.4
1.82
901
65.4
1.65
890
78.4
1.85
*/