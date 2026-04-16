#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main() {
	srand(time(NULL));
	
	int x[5][5];
	
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			x[i][j] = 0 + rand()%8;
		}
	}
	
	cout<<"Matriz original (M): "<<endl;
	
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	int y[5][5];
	
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			int s = 0;
			for (int m = i-1; m<= i+1; m++) {
				for (int n = j-1; n<= j+1; n++) {
					if (not (m < 0 or n < 0 or m > 4 or n > 4)) { //es decir, que este dentro de la matriz
						s += x[m][n];
					}
				}
			}
			int media = (s + 4.5)/9;
			
			y[i][j] = media;
		}
	}
	
	cout<<"La nueva matriz N es: "<<endl;
	
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			cout<<y[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
