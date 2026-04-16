#include<iostream>
#include<stdlib.h>
#include<time.h>

//Venta de instrumentos. Obs: No se verifico por completo la precision del codigo.

using namespace std;

int main() {
	srand(time(NULL));
	
	int x[5][4][12];
	int mayorventatotal;
	int valormayorventatotal;
	
	int minventaanual;
	int valorminventaanual;
	
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<4; j++) {
			int s = 0;
			for (int k = 0; k<12;k++) {
				int e = -1;
				/*if (j == 0) {
					
					do {cout<<"Ingrese la cantidad de ventas de los instrumentos de cuerdas en la tienda "<<i+1<<" en el mes "<<k+1<<": ";cin>>e;} while (e<0);
				} 
				if (j == 1) {
				
					do {cout<<"Ingrese la cantidad de ventas de los instrumentos de viento en la tienda "<<i+1<<" en el mes "<<k+1<<": ";cin>>e;} while (e<0);
				} 
				if (j == 2) {
			
					do {cout<<"Ingrese la cantidad de ventas de los instrumentos de percusion en la tienda "<<i+1<<" en el mes "<<k+1<<": ";cin>>e;} while (e<0);
				} 
				if (j == 3) {
				
					do {cout<<"Ingrese la cantidad de ventas de los instrumentos electronicos en la tienda "<<i+1<<" en el mes "<<k+1<<": ";cin>>e;} while (e<0);
				} */
				x[i][j][k] = 10000 + rand()%90000;
				s+=e;
			}
			
			if (i == 0 and j == 0) {
				minventaanual = i*10 + j;
				valorminventaanual = s;
			}
			else {
				if (s < valorminventaanual) {
					minventaanual = i*10 + j;
					valorminventaanual = s;
				}
			}
		}
	}
	
	for (int i = 0; i<5;i++) {
		for (int k = 0; k<12; k++) {
			int s = 0;
			for (int j = 0; j<4; j++) {
				s+=x[i][j][k];
			}
			
			if (i==0 and k==0) {
				mayorventatotal = 100*i + k;
				valormayorventatotal = s;
			} else {
				if (s > valormayorventatotal) {
					mayorventatotal = 100*i + k;
					valormayorventatotal = s;
				}
			}
		}
	}
	
	cout<<"La mayor venta total ocurrio en la tienda "<<mayorventatotal/100<<" en el mes "<<mayorventatotal%100<<endl;
	cout<<"La menor venta anual fue en la tienda "<<minventaanual/10<<" con el instrumento "<<minventaanual%10<<endl;
	
	
	
	return 0;
}
