#include<iostream>

using namespace std;

void permutar(string palabras[], int inicio, int fin) {
	if (inicio == fin) {
		for(int i = 0; i<=fin; i++) {
			cout<<palabras[i]<<" ";
		}
		cout<<endl;
	} else {
		for (int i = inicio; i<=fin; i++) {
			string t = palabras[i];
			palabras[i] = palabras[inicio];
			palabras[inicio] = t;
			
			permutar(palabras, inicio+1,fin);
			
			t = palabras[i];
			palabras[i] = palabras[inicio];
			palabras[inicio] = t;
		}
	}
}

int main() {
	int n = 0;
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	string x[n];
	cin.ignore();
	for (int i = 0; i<n; i++) {
		cout<<"x["<<i<<"]: ";getline(cin, x[i]);
	}
	
	permutar(x, 0, n-1);
}