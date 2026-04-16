#include<iostream>

using namespace std;

int extraerpregunta(long long int num, int preg) {
	int cantcif = 10;
	
	for (int i = 0; i<cantcif-preg-1; i++) {
		num/=10;
	}
	
	int c = num%10;
	
	return c;
}

int main() {
	
	int n = 0;
	do {
		cout<<"Cantidad de encuestados: ";cin>>n;
	} while (n<=0);
	
	struct persona{
		char sexo;
		long long int enc;
	} x[n];
	
	int cantvarones = 0;
	
	for (int i = 0; i<n; i++) {
		char s = ' ';
		do {
			cout<<"Sexo (M/F) de la persona "<<i+1<<": ";cin>>s;

		} while (s != 'M' and s!= 'F' and s != 'm' and s!= 'f');
		
		if (s == 'm') s = 'M';
		if (s == 'f') s = 'F';
		
		x[i].sexo = s;
		if (x[i].sexo == 'M') cantvarones++;
		
		long long int valor = -1;
		do {
			cout<<"Encuestas: ";cin>>valor;
		} while (valor < 0);
		
		
		x[i].enc = valor;
	}
	
	int frecuencianosabe[10];
	for (int i = 0; i<10; i++) frecuencianosabe[i] = 0;
	
	int frecuenciacincovarones[10];
	for (int i = 0; i<10; i++) frecuenciacincovarones[i] = 0;
	
	int frecuenciacincomujeres[10];
	for (int i = 0; i<10; i++) frecuenciacincomujeres[i] = 0;
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<10; j++) {
			if (extraerpregunta(x[i].enc, j) == 0) {
				frecuencianosabe[j]++;
			}
			
			if (extraerpregunta(x[i].enc, j) == 5) {
				if (x[i].sexo == 'M') frecuenciacincovarones[j]++;
				if (x[i].sexo == 'F') frecuenciacincomujeres[j]++;
			} 
		}
	}
	
	float porcvarones = cantvarones*100.0/n;
	cout<<"Se tiene un "<<porcvarones<<"% de participacion masculina y "<<100-porcvarones<<"% de participacion femenina"<<endl;
	int mayor;
	mayor = 0;
	for (int i = 0; i<10; i++) {
		if (frecuencianosabe[i] > frecuencianosabe[mayor]) mayor = i;
	}
	
	cout<<"Mayor porcentaje de no sabe, no opina: pregunta "<<mayor+1<<endl;
	
	mayor = 0;
	bool flag = false;
	for (int i = 0; i<10; i++) {
		if (frecuenciacincovarones[i] > frecuenciacincovarones[mayor]) mayor = i;
		if (frecuenciacincovarones[i]==frecuenciacincovarones[mayor] and i!=0) {
			flag = true;
		}
	}
	
	cout<<"Mejor opinion de sexo masculino: pregunta "<<mayor+1;
	if (flag) {
		for (int i = 0; i<10; i++) {
		if (frecuenciacincovarones[i] == frecuenciacincovarones[mayor] and i!=mayor) {
			cout<<", pregunta "<<i+1;
		}
		}	
	}
	
	
	cout<<endl;
	flag = false;
	mayor = 0;
	for (int i = 0; i<10; i++) {
		if (frecuenciacincomujeres[i] > frecuenciacincomujeres[mayor]) mayor = i;
		if (frecuenciacincomujeres[i]==frecuenciacincomujeres[mayor] and i!=0) {
			flag = true;
		}
	}
	
	cout<<"Mejor opinion de sexo femenino: pregunta "<<mayor+1;
	if (flag) {
		for (int i = 0; i<10; i++) {
		if (frecuenciacincomujeres[i] == frecuenciacincomujeres[mayor] and i!=mayor) {
			cout<<", pregunta "<<i+1;
		}
		}	
	}
	cout<<endl;
	
	return 0;
}
