#include<iostream>

using namespace std;
int main() {
	int n = 0;
	
	do {
		cout<<"Ingrese la cantidad de estudiantes: ";cin>>n;
	} while (n<=0);
	
	int notas[n][5];
	int suma[5] = {0};
	float aprobados = 0;
	
	for (int i = 0; i<n; i++) {
		int notaalumno = 0;
		for (int j = 0; j<5; j++) {
			int e = -1;
			do {
			cout<<"Ingrese el puntaje del alumno "<<i+1<<" en la pregunta "<<j+1<<": ";cin>>e;
			} while (e < 0 or e > 4);
			notas[i][j] = e;
			notaalumno+=e;
			suma[j]+=e;
		}
		
		if (notaalumno >= 10) {
			aprobados++;
		}
	}
	
	int max = 0;
	int min = 0;
	
	for (int i = 0; i<5; i++) {
		if (i == 0) {max = 1; min = 1;
		} else {
			if (suma[max%10-1] < suma[i]) {
				max = i+1;
			} else if (suma[max%10-1] == suma[i]) {
				max*=10;
				max+=i+1;
			}
			
			if (suma[min%10-1] > suma[i]) {
				min = i+1;
			} else if (suma[min%10-1] == suma[i]) {
				min*=10;
				min+=i+1;
			}
		}
	}
	
	float fa = aprobados/n;
	float pa = fa*100;
	
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<5; j++) {
			cout<<notas[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Porcentaje de aprobados: "<<pa<<"%. Porcentaje de desaprobados: "<<100-pa<<"%."<<endl;
	cout<<"Preguntas mas faciles: ";
	while (max > 0){
		cout<<max%10<<" ";
		max/=10;
	}
	cout<<endl<<"Preguntas mas dificiles: ";
	while (min>0) {
		cout<<min%10<<" ";
		min/=10;
	}
	
	return 0;
}
