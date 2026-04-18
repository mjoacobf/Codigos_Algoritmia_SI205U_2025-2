#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> valores;
	
	int n = 0;
	int sum = 0;
	do {
		cout<<"Ingrese el numero de trabajadores: ";cin>>n;
	} while (n<=1);
	
	int i = 0;
	while (i<n*3 -1) {
		if (i%3 == 0) {
			int cod = 0;
			do {
				cout<<"Ingrese el codigo del trabajador "<<i/3 + 1<<" (tres digitos): ";cin>>cod;
			} while (cod<100 or cod>999);
			
			valores.push_back(cod);
		} else if (i%3 == 1) {
			int th = 0;
			do {
				cout<<"Ingrese el total de horas trabajadas a la semana (de 10 a 30) del trabajador "<<1 + i/3<<": ";cin>>th;
			} while (th < 10 or th > 30);
			
			valores.push_back(th);
			sum+=th;
		} else {
			valores.push_back(-1);
		}
		
		i++;
	}
	
	float prom = sum*1.0/n;
	
	cout<<"Promedio de horas trabajadas: "<<prom<<endl;
	
	for (int i = 0; i<n; i++) {
		if (valores[i*3 + 1]*1.0 < prom) {
			for (int j = i; j<n-1; j++) {
				valores[j*3] = valores[j*3 + 3];
				valores[j*3 + 1] = valores[j*3 + 4];
			}
			
			valores.pop_back();
			valores.pop_back();
			valores.pop_back();
			i = -1;
		}
	}
	
	for (int i = 0; i<n; i++) {
		for (int j = n-1; j>i; j--) {
			if (valores[i*3] > valores[j*3]) {
				int t1 = valores[j*3];
				int t2 = valores[j*3 + 1];
				
				valores[j*3] = valores[i*3];
				valores[j*3 + 1] = valores[i*3 + 1];
				
				valores[i*3] = t1;
				valores[i*3 + 1] = t2;
			}
		}
	}
	
	for (int i = 0; i<valores.size(); i++) {
		cout<<valores[i]<<" ";
	}
	
	
	return 0;
}