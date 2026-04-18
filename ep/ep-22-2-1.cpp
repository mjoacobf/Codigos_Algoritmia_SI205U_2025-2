#include<iostream>

using namespace std;

int main() {
	int n = 0;
	
	do {
		cout<<"n (<=50): ";cin>>n;
	} while (n>50 or n<=0);
	
	int x[n];
	
	for (int i = 0; i<n; i++) {
		int cod = 0;
		do {
			cout<<"Codigo "<<i+1<<" (3 cif): ";cin>>cod;
		} while (cod < 100 or cod > 999);
		
		x[i] = cod;
		
		float p = 0;
		do {
			cout<<"Precio "<<i+1<<" (1.00-9.90): ";cin>>p;
		} while (p < 1.0 or p>9.9);
		
		p*=10;
		
		x[i]*=100;
		x[i]+=p;
		
		int tipo = 0;
		do {
			cout<<"Tipo "<<i+1<<" (A = 1, B = 2, C = 3): ";cin>>tipo;
		} while (tipo <1 or tipo > 3);
		
		x[i]*=10;
		x[i]+=tipo;
	}
	
	cout<<"Arreglo original:"<<endl;
	cout<<"Cod\tPrecio\tTipo"<<endl;
	for (int i= 0; i<n; i++) {
		int t = x[i];
		cout<<t/1000<<"\t";
		t/=10;
		int u = t%100;
		cout<<u*1.0/10<<"\t";
		
		if (x[i]%10 == 1) cout<<"A";
		if (x[i]%10 == 2) cout<<"B";
		if (x[i]%10 == 3) cout<<"C";
		cout<<endl;
	}
	
	// Primer ordenamiento
	
	for (int i = 0; i<n; i++) {
		for (int j = n-1; j>i; j--) {
			if (x[i]%10 > x[j]%10) {
				int t = x[j];
				x[j] = x[i];
				x[i] = t;
			} else if (x[i]%10 == x[j]%10) {
				int t1 = x[i]/10;
				int t2 = x[j]/10;
				
				if (t1%100 < t2%100) {
					int t = x[j];
					x[j] = x[i];
					x[i] = t;
				}
			}
		}
	}
	
	cout<<"Despues de ordenar:"<<endl;
	cout<<"Cod\tPrecio\tTipo"<<endl;
	for (int i= 0; i<n; i++) {
		int t = x[i];
		cout<<t/1000<<"\t";
		t/=10;
		int u = t%100;
		cout<<u*1.0/10<<"\t";
		
		if (x[i]%10 == 1) cout<<"A";
		if (x[i]%10 == 2) cout<<"B";
		if (x[i]%10 == 3) cout<<"C";
		cout<<endl;
	}
	
	// Hallando el promedio de precios del tipo B
	
	int sum = 0;
	int cont = 0;
	for (int i = 0; i<n; i++) {
		if (x[i]%10 == 2) {
			int t = x[i]/10;
			sum+=t%100;
			cont++;
		}
	}
	
	float prom = sum*1.0/cont;
	cout<<"Promedio: "<<prom*0.1<<endl;
	
	//Eliminacion
	for (int i = 0; i<n; i++) {
		if (x[i]%10 == 2) {
			int t = x[i]/10;
			int p = t%100;
			if (p*1.0 < prom) {
				for (int j = i; j<n-1; j++) {
					x[j] = x[j+1];
				}
				n--;
				i--;
			}
		}
	}
	
	cout<<"Despues de eliminar:"<<endl;
	cout<<"Cod\tPrecio\tTipo"<<endl;
	for (int i= 0; i<n; i++) {
		int t = x[i];
		cout<<t/1000<<"\t";
		t/=10;
		int u = t%100;
		cout<<u*1.0/10<<"\t";
		
		if (x[i]%10 == 1) cout<<"A";
		if (x[i]%10 == 2) cout<<"B";
		if (x[i]%10 == 3) cout<<"C";
		cout<<endl;
	}
	
	n++;
	cout<<"Ingrese los datos del adicional:"<<endl;
	int cod = 0;
		do {
			cout<<"Codigo (3 cif): ";cin>>cod;
		} while (cod < 100 or cod > 999);
		
		x[n-1] = cod;
		
		float p = 0;
		do {
			cout<<"Precio (1.00-9.90): ";cin>>p;
		} while (p < 1.0 or p>9.9);
		
		p*=10;
		
		x[n-1]*=100;
		x[n-1]+=p;
		
		int tipo = 0;
		do {
			cout<<"Tipo (A = 1, B = 2, C = 3): ";cin>>tipo;
		} while (tipo <1 or tipo > 3);
		
		x[n-1]*=10;
		x[n-1]+=tipo;
	
	// Otra vez ordenado
	
	for (int i = 0; i<n; i++) {
		for (int j = n-1; j>i; j--) {
			if (x[i]%10 > x[j]%10) {
				int t = x[j];
				x[j] = x[i];
				x[i] = t;
			} else if (x[i]%10 == x[j]%10) {
				int t1 = x[i]/10;
				int t2 = x[j]/10;
				
				if (t1%100 < t2%100) {
					int t = x[j];
					x[j] = x[i];
					x[i] = t;
				}
			}
		}
	}
	
	cout<<"Despues de ordenar:"<<endl;
	cout<<"Cod\tPrecio\tTipo"<<endl;
	for (int i= 0; i<n; i++) {
		int t = x[i];
		cout<<t/1000<<"\t";
		t/=10;
		int u = t%100;
		cout<<u*1.0/10<<"\t";
		
		if (x[i]%10 == 1) cout<<"A";
		if (x[i]%10 == 2) cout<<"B";
		if (x[i]%10 == 3) cout<<"C";
		cout<<endl;
	}
	
	return 0;
}
/*
9
333
4.5
1
222
7.4
2
111
3.2
3
432
2.4
1
945
6.9
1
392
3.1
2
444
7.1
2
732
2.8
3
839
2.5
2
855
5.10
3
*/